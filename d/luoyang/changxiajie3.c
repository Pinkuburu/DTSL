
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长夏大街");
  set ("long", @long
这里是洛阳的长夏街。

long);

  set("exits", ([ 
	  "north":__DIR__"changxiajie2",
	  "west":__DIR__"liangchang2",
  	  "south":__DIR__"changxiajie4",
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

