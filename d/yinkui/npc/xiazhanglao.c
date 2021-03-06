
inherit NPC;

#include <ansi.h>

string do_quest1();
int do_quest2();

void create()
{
   set_name("霞长老",({ "xia zhanglao","xia","zhanglao" }) );
        set("gender", "女性" );
		
        set("age", 38);
   set("long", "她就是阴癸派的长老之一。\n");
   set("per",20);
   set("combat_exp",600000);
  
   set_skill("dodge",180);
   set_skill("parry",180);
   set_skill("force",180);
   set_skill("strike",180);
   set_skill("cuff",180);
   set_skill("sword",180);
   
   set_skill("jiutian-huanzhang",180);
   set_skill("literate",180);
   set_skill("tianmo-dafa",180);
   set_skill("tianmo-huanzong",180);
   set_skill("linglong-yuquan",180);
  
   set("max_gin",1500);
   set("max_kee",1500);
   set("max_sen",1500);
   set("force",2000);
   set("max_force",2000);
   create_family("阴癸派",5,"长老");
   set("inquiry",([
   "天魔阵":(:do_quest1:),
   "考验":(:do_quest2:),
   ]));
   setup();
   
}

string do_quest1()
{
  object ob;
  
  ob=this_player();
  
  if(ob->query("dtsl_quest_yinguifinal"))
  return "凭你的功夫学习天魔阵太可惜了！\n";
  
  if(ob->query_temp("tmz_quest/pass_xia"))
  return "你的功夫我已经考验过了，你去问其他长老吧！\n";
  
  ob->set_temp("tmz_quest/xia_step1",1);
  
  return "想学天魔阵？先打败我再说吧！\n";
}

int surrender(object killer,object victim)
{
   if(!killer->query_temp("tmz_quest/xia_step1"))
   return 1;
   killer->delete_temp("tmz_quest/xia_step1");
   killer->set_temp("tmz_quest/xia_step2",1);
   
   message_vision(CYN"\n$N"+CYN+"脸色一变，朝$n"+CYN+"道："+RANK_D->query_respect(killer)+"果然身手不凡！\n"+
   "不过我还是要考验你一下！\n"NOR,victim,killer);
   return 1;
}

int do_quest2()
{
   object ob;
   
   ob=this_player();
   if(!ob->query_temp("tmz_quest/xia_step2")){
     command("say 不战胜我就想接受考验吗？\n");
     return 1;
   }
   
   message_vision("\n$N朝$n笑道：武学讲究气势为攻击之本！下面我就给你示范一下，\n"+
   "看你能不能领略其中的奥秘！\n",this_object(),ob);
   tell_object(ob,"\n"+query("name")+"突然向你发动攻击！！\n");
   add_temp("apply/damage",300);
   
   COMBAT_D->do_attack(this_object(),ob,query_temp("weapon"),0,2);
   add_temp("apply/damage",-300);
   call_out("do_quest3",1,ob);
   return 1;
}

void do_quest3(object ob)
{
  string msg;
  
  if(!ob)
  return;
  if(ob->is_ghost()){
   tell_object(ob,"你没有经受住"+query("name")+"的考验，下次吧！！\n");
   return;
  }
  if(!living(ob))
   return;
  
  msg="\n$N朝$n嘿嘿一笑：好！我这关你过了！\n";
  message_vision(msg,this_object(),ob);
  
  ob->delete_temp("tmz_quest/xia_step2");
  ob->set_temp("tmz_quest/pass_xia",1);
  
  return;
}