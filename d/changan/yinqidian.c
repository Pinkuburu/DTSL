
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","银器店");
  set ("long", @LONG
这里是位于都会市内的一家银器店，专门为顾客制作各种银饰用品，
点到处都摆放着制作好的样品，有银手镯，银索，银佛像等等，银光闪
闪，琳琅满目。
LONG);

  set("exits", ([ 
 "east":__DIR__"dongshixijie5",
       ]));
  set("objects",([
         __DIR__"npc/huoji1":1,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

