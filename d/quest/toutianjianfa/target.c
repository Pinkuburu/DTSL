
inherit JOBNPC;
#include <ansi.h>
#include <job_money.h>

void create()
{
   int flag;
   
   flag=random(2);
   
   if(flag==0)
    set_name("商旅",({ "shang lv","shang","lv" }) );
   else
    set_name("官兵",({ "guan bing","guan","bing" }) );
    
   set("gender", "男性" );
   set("age",35);
   
   if(flag==0)
   set("long", "这是一名商旅，看起来很有钱。\n");
   else
   set("long", "这是一名官兵，看起来搜刮了不少民脂民膏。\n");
             
   set("chat_chance",20);
   set("chat_msg",({
    (:random_move:),
    
   }));
   
   if(flag==0)
    set("job_type","不杀死");
   else
    set("job_type","杀死");
   
   setup();
  
}

string long()
{
  if(query("target_id")==this_player()->query("id")){
    command("say 臭马贼，休想打我的主意！！\n");
    kill_ob(this_player());
    return "";
  }
  return query("long");
}

int clear()
{
  if(time()-query("last")<4000)
  return 0;
  if(!query("no_msg")){
  message_vision("$N匆匆地走了。\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;
}

void dispear()
{
   destruct(this_object());
   return;
}


int chat()
{
   object ob;
   if(clear())
   return 1;
   
   return ::chat();
}

int set_status(object ob)
{
   
   set("combat_exp",ob->query("combat_exp"));
   if(ob->query("combat_exp")<150000)
    set_this_skills("low");
   else
   if(ob->query("combat_exp")<800000)
    set_this_skills("middle");
   else
    set_this_skills("high");
    
   set_all_skill(this_object(),ob->query("max_pot")-100);
   
   copy_hp_item(ob,this_object(),"gin");
   copy_hp_item(ob,this_object(),"kee");
   copy_hp_item(ob,this_object(),"sen");
   
   set("max_force",ob->query("max_force"));
   set("force",ob->query("max_force"));
   set("target_id",ob->query("id"));
   set("last",time()+600);
   
   if(query("job_type")=="杀死")
   return 1;
   else
   return 2;
}

void die()
{
  object ob;
  
  ob=query_temp("last_damage_from");
  if(!ob||ob->query("id")!=query("target_id"))
  return ::die();
  
  if(query("job_type")=="杀死"){
    tell_object(ob,"你成功地打劫了官兵！\n");
    JOBSYS_D->give_reward_mazei(ob);
    return ::die();
  }
  
  tell_object(ob,"\n你本次打劫行动失败了！！\n");
  ob->set("dtsl_quest_toutianjf_fail",1);
  ob->delete_temp("mazei_job");
  ob->delete_temp("dtsl_job");
  return ::die();
}

void unconcious()
{
   object ob;
  
  ob=query_temp("last_damage_from");
  if(!ob||ob->query("id")!=query("target_id"))
  return ::unconcious();
  
  if(query("job_type")=="杀死"
  ||ob->is_killing(query("id"))){
    return ::unconcious();
  }
  
  tell_object(ob,"你成功地打劫了"+query("name")+"！\n");
  JOBSYS_D->give_reward_mazei(ob);
  
  message_vision("\n$N一脚将$n踹起，$n吓得马上跑了！！\n",ob,this_object());
  if(query("job_type")!="杀死")
  destruct(this_object());
  return;
}