
#include <ansi.h>
inherit ROOM;

int do_pa();
void create ()
{
  set ("short","山脚");
  set ("long", @LONG
这里是大巴山的山脚下。大巴山以险峻著称，所以翻过大巴山也是
一件十分不容易的事。只见眼前怪石嶙峋，险峰骑出，不愧为一险地。
眼前没有什么路，看来你只有往上爬(pa)了。
LONG);

  set("exits", ([ 

   "east":"/d/xiangyang/tulu2",
       ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_pa","pa");
}

int do_pa()
{
   object me;
   me=this_player();
   if(me->query("sen")<15)
   return notify_fail("你试图爬上去，可是精神疲倦，根本使不上半点力气。\n");
 if(me->query_temp("track"))
 return notify_fail("你正赶着盐车，根本爬不上去。\n");
   me->add("sen",-15);
   message_vision("$N看准一个地方，用双手抓住，爬了上去。\n",me);
   tell_room(__DIR__"shanji1",me->name()+"爬了上来！\n");
   me->move(__DIR__"shanji1");
   return 1;
}
