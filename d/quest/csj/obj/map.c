
#include <ansi.h>
inherit ITEM;
int do_look(string arg);
void create()
{
        set_name(YEL"羊皮卷" NOR, ({ "yangpi juan","juan" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
	        set("material", "羊皮");
                set("no_drop",1);
                set("no_sell",1);
                set("no_give",1);
                set("no_steal",1);
        }
        setup();
}
void init()
{
  add_action("do_look","kan");
}
int do_look(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="羊皮卷")
  return notify_fail("你要看什么？\n");
  if(!ob->query_temp("dtsl_quest_csj/step7"))
  return 0;
  if(!ob->query_temp("dtsl_quest_csj/check_time"))
  ob->set_temp("dtsl_quest_csj/check_time",time());
  if(time()-ob->query_temp("dtsl_quest_csj/check_time")
     <3600*(31-ob->query("kar"))||
     time()-ob->query_temp("dtsl_quest_csj/check_time")
     >3600*(31-ob->query("kar"))+30){
   tell_object(ob,"你看到上面写着：\n"+
     "这里聚集了五湖四海的人们,再加上是烟花胜地,\n"+
     "所以江湖的豪客都要来这里逛逛,以显示自己的英雄本色。\n");
   return 1;}
  tell_object(ob,"这里是一个山洞，平时几乎没有人来这里。\n"+
                 "山洞的外面绿树环绕，风景秀丽，不时传来\n"+
                 "几声鸟鸣叫的声音。\n");
  ob->delete_temp("dtsl_quest_csj/step7");
  ob->set_temp("dtsl_quest_csj/step8",1);
  return 1;
}

