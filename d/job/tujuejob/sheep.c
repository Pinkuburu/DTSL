
inherit NPC;

#include <job_money.h>

int do_wei(string arg);

void create()
{
   set_name("绵羊",({ "sheep"}) );
        set("race", "野兽" );
        set("combat_exp",20000);
     set("long", "这是一只绵羊。\n");
	 set("verbs",({"hoof"}));
	 set("target_id","####");
     set("limbs",({"头","尾巴","腹部","腰部"}));
  setup();

}

int accept_fight(object ob)
{
   return 0;
}

void init()
{
  add_action("do_wei","wei");
}

int do_wei(string arg)
{
   object ob,target;
   
   ob=this_player();
   
   if(!arg) return notify_fail("你要喂什么？\n");
   
   if(!objectp(target=present(arg,environment(ob))))
   return notify_fail("这里没有这个东西。\n");
   
   if(target->query("owner")!=ob)
   return notify_fail("你弄错对象了吧？？\n");
   
   if(target->query("place")!=base_name(environment(ob))+".c")
   return notify_fail("你好象走错地方了。\n");
   
   if(ob->is_busy())
   return notify_fail("你正忙着呢！\n");
   
   if(this_object()->is_busy())
   return notify_fail("对方正忙着呢！\n");
   
   if(ob->is_fighting())
   return notify_fail("你先打完仗吧！\n");
   
   if(this_object()->is_fighting())
   return notify_fail("对方正在战斗中！\n");
   
   if(query("job_ok")){
     tell_object(ob,query("name")+"已经吃饱了，不用再喂了。\n");
   return 1;
    }
   
   tell_object(ob,"你从地上拔了些草，喂给"+query("name")+"吃了。\n");
   
   if(ob->query("combat_exp")>=50000&&!query("flag")){
     set("flag",1);
     call_out("wolf_come",5+random(3),ob);
     }
   
   add("food",1);
   ob->receive_damage("sen",10+random(5));
   
   if(query("food")>=10+random(5)){
   
   set("job_ok",1);
   tell_object(ob,query("name")+"已经吃饱了，不用再喂了。\n");
   return 1;
    }
   ob->start_busy(random(2));
   this_object()->start_busy(random(2));
   return 1;
   
}

void wolf_come(object ob)
{
   object beast;
   
   beast=new(__DIR__"wolf");
   beast->set("combat_exp",ob->query("combat_exp"));
   
   copy_hp_item(ob,beast,"kee",2/3);
   
   beast->move(environment());
   tell_object(ob,"\n\n突然纵出一只"+beast->query("name")+
   "朝"+query("name")+"扑去！！\n\n");
   
   beast->kill_ob(this_object());
   
   return;
}