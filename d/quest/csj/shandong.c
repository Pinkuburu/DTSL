inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIB"山洞"NOR);
	set("long", @LONG
这里是一个山洞，平时几乎没有人来这里。山洞的外面绿树环绕，
风景秀丽，不时传来几声鸟鸣叫的声音。
LONG);
        set("exits",([
          "out":"/d/hengshan/yuyang",
          ]));
        setup();      
}

void init()
{
  
  add_action("do_lingwu","lingwu");
}

int do_lingwu(string arg)
{
  object ob;
  string str1,str2;
  
  ob=this_player();
  if(!arg)
  return notify_fail("你要领悟什么内功？\n");
  if(arg!="changsheng-jue")
  return notify_fail("这里不能领悟这种内功！\n");
  
  if(ob->query_skill("changsheng-jue",1)<150)
  return notify_fail("你的长生诀修为太低！\n");
  
  if(ob->query("force_quest/csj_fail"))
   return notify_fail("你发现根本无法领会到长生诀真正的精髓！\n");
     
  if(ob->query("force_quest/csj_ok"))
  return notify_fail("你已经领悟出长生诀精髓了。\n");
  
  if(!ob->query("force_quest/no_check_csj"))
   if(ob->query("force_quest/csj_PKS")!=ob->query("PKS")
   ||ob->query("force_quest/csj_deadtimes")!=ob->query("deadtimes")
    ){
      ob->set("force_quest/csj_fail",1);
      tell_object(ob,"你发现根本无法领会到长生诀真正的精髓！\n");
      return 1;
   }
  
  if(ob->query_kar()<29){
   tell_object(ob,RED"你吐了一口鲜血，看来暂时还无法领会长生诀的精髓！\n"NOR);
   ob->set_skill("changsheng-jue",10);
   ob->set("force_quest/no_check_csj",1);
   ob->add("force_quest/csj_fail_times",1);
   if(ob->query("force_quest/csj_fail_times")>=2){
   	ob->set("force_quest/csj_fail",1);
    tell_object(ob,"\n你发现根本无法领会到长生诀真正的精髓！\n");		   
   }
   return 1;
  }
  
  
  ob->set("force_quest/csj_ok",1);
  tell_object(ob,"\n你突然灵光一现，领会到了长生诀的精髓之处！\n");
  return 1;
}
