
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","青石路");
  set ("long", @LONG
这里是一条青石路，西边是飞马牧场的菜园。南边是飞马牧场的园
林。有几个工人从这里走过，看样子是去菜园种菜干活的。
LONG);

  set("exits", ([ 
	  "west":__DIR__"caodi2",
	  "southeast":__DIR__"yuanlin",
    ]));
  set("objects",([
	  __DIR__"npc/wuzhao-ru":1,
	  ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

