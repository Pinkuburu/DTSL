
#include <ansi.h>
inherit ROOM;
int do_bo(string arg);
void create ()
{
  set ("short","松树");
  set ("long", @LONG
你停留在一株松树之上。这棵松树从悬崖的边上盘旋而上，
正好把你接住了。下边就是山崖的底部，黑乎乎的，什么也看不
清。松树的根部杂草从生，似乎可以拨「bo」开。
LONG);
  set("valid_startroom", 1);
  setup();
 
}
void init()
{
   add_action("do_bo","bo");
}
int do_bo(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="杂草")
  return notify_fail("你要拨什么？\n");
  message_vision(YEL"$N用手拨开杂草，杂草后面闪现出一个洞口！\n"NOR,ob);
  set("exits/enter",__DIR__"dongming");
  call_out("del_enter",5);
  return 1;
}
void del_enter()
{
  delete("exits/enter");
  remove_call_out("del_enter");
}
