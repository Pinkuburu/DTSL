
#include <ansi.h>
inherit ROOM;
int do_jump(string arg);
void create ()
{
  set ("short",HIB"山崖"NOR);
  set ("long", @LONG
这里是一山崖，下面深不见底，只见白云从脚下轻轻飘过。
你站在这里，不禁腿脚直打颤。一阵大风出来，几乎把你吹到
悬崖下面去。
LONG);

  set("exits", ([ 
 "north":"/d/dongming/shulin2",
        ]));
  set("valid_startroom", 1);
  setup();
 
}
void init()
{
   add_action("do_jump","jump");
}
int do_jump(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="cliff")
  return notify_fail("你要往哪里跳？\n");
  if(ob->query("pker"))
  return notify_fail("通缉犯还是老实点吧！\n");
  message_vision(YEL"$N一腾身，朝悬崖下边跳了下去！\n"NOR,ob);
  if(ob->query("family_lingwu")!="dongming"||
     !ob->query("no_check_jump")){
  	ob->receive_wound("kee",2);
  	ob->move(__DIR__"yadi");
  	tell_object(ob,"你感觉双腿发麻，一步也走不了了，看来要休息一会了！\n");
  	//ob->add("no_check_jump",1);
  	ob->start_busy(300);
  	return 1;}
  tell_object(ob,"凌空下落之中，你突然被一个松树接住了！\n");
  ob->move(__DIR__"songshu");
  return 1;
}
