
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","金器店");
  set ("long", @LONG
这里是位于都会市内的一家金器店，专门为顾客制作各种金饰用品，
点到处都摆放着制作好的样品，有金手镯，金索，金佛像等等，金光闪
闪，琳琅满目。
LONG);

  set("exits", ([ 
 "west":__DIR__"dongshixijie5",
       ]));
  set("objects",([
         __DIR__"npc/huoji2":1,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

