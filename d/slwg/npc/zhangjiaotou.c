
inherit NPC;
#include <ansi.h>

string give_job();
int do_ok(string arg);

void create()
{
   set_name("张教头",({ "zhang jiaotou","zhang","jiao","tou"}) );
        set("gender", "男性" );
        set("age", 32);
        
        set("str",30);
        set("dex",30);
        
        set("slwg_jiaotou",1);
        set("target_id","####");
        set("long","这是石龙武馆的教头。\n");
        
        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("force",80);
        set_skill("cuff",80);
        
        set_skill("male-cuff",30);
        set_skill("babu-ganchan",80);
        
        set("max_force",200);
        set("force",200);
        
        set_temp("apply/damage",10+random(10));
        
        set("combat_exp",50000);
        
        set("inquiry",([
           "武艺":(:give_job:),
           ]));
        
    setup();
   
}
/*
void init()
{
   object ob;
   
   ob=this_player();
   if(!ob) return;
   remove_call_out("welcome");
   call_out("welcome",1,ob);
}

void welcome(object ob)
{
   if(!ob) return;
   
   if(environment(ob)!=environment())
   return;
   
   
     command("hi "+ob->query("id"));
     tell_object(ob,query("name")+"朝你笑道：快来和我 "+HBMAG+HIW+"qiecuo jiao"+NOR+" 吧。\n");
  return;
}*/

void init()
{
  add_action("do_ok","task");
}

int accept_fight(object who)
{
   return 0;
}

void kill_ob(object ob)
{
  ob->remove_killer(this_object());
  command("bi "+ob->query("id"));
  return;
}


string *jobs=({
"梅花桩","站桩","举石锁","打沙袋"
});
  
string give_job()
{
   object ob;
   int i;
   
   ob=this_player();
   
   if(ob->query("combat_exp")>=20000)
   return "你的经验这么高，在武馆练习武艺可太慢了！\n";
   
   if(time()-ob->query("busy_time")<10+random(5))
    return "学习武艺不要急噪，你先休息一下。\n";
   
   if(ob->query_temp("slwg_job"))
   return "我不是让你去练习"+ob->query_temp("slwg_job")+"吗？"+
   "怎么还在偷懒啊？？\n";
   
   i=random(sizeof(jobs));
   
   ob->set_temp("slwg_job",jobs[i]);
   
   return "我看你天资不错，就去练武场去练习"+jobs[i]+"吧 "+HIG+"(lianwu "+jobs[i]+")"+NOR+
          "\n可千万不要偷懒！\n";
}
   
int do_ok(string arg)
{
   object ob;
   int exp,pot,sil;
  
   ob=this_player();
   
   if(!ob->query_temp("slwg_job"))
   return notify_fail("你说什么我可听不懂啊！\n");
   
   if(!ob->query_temp("slwg_job_ok"))
   return notify_fail("我让你练习武艺，你却偷懒，真是该打！\n");
   
   ob->delete_temp("slwg_job");
   ob->delete_temp("slwg_job_ok");
   ob->delete_temp("slwg_job_times");
   
   exp=20+random(10);
   pot=5+random(5);
   sil=100+random(100);
   
   ob->add("combat_exp",exp);
   ob->add("potential",pot);
   if(ob->query("potential")>ob->query("max_pot"))
    ob->set("potential",ob->query("max_pot"));
   ob->add("deposit",sil);
   
   ob->set("busy_time",time());
   
   ob->save();
   
   tell_object(ob,query("name")+"笑道：好样的！将来你一定能为我们石龙武馆争气！\n");
   tell_object(ob,query("name")+"奖励了你"+HIW+chinese_number(exp)+NOR+"点经验，"+
   HIY+chinese_number(pot)+NOR+"点潜能。\n"+
   MONEY_D->money_str(sil)+"。\n");
   
   return 1;
}