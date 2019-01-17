
#include <ansi.h>
inherit ROOM;
int do_clear(string arg);
void create ()
{
  set ("short",HIB"密室"NOR);
  set ("long", @LONG
这里是一间密室，看起来已经很久没有人来过了。前面放着
一张床，上面积了厚厚的一层尘土。旁边还有一个扫帚，看来是
用来扫尘土的。
LONG);

 set("exits",([ "out":"/d/yinkui/woshi2",]));
  set("valid_startroom", 1);
  setup();
 
}
void init()
{
   add_action("do_clear","sao");
}
int do_clear(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="床")
  return notify_fail("你要扫什么？\n");
  message_vision(YEL"$N仔细地扫起尘土来。\n"NOR,ob);
  tell_object(ob,"突然床的被褥掀起一角，显现出一个黑洞来！\n");
  set("exits/enter",__DIR__"yingui");
  call_out("del_enter",5);
  return 1;
}
void del_enter()
{
  delete("exits/enter");
  remove_call_out("del_enter");
}
