
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长夏大街");
  set ("long", @long
这里是洛阳的长夏街。这里比较寂静，西面是一个驿站。偶尔传来
马匹的嘶鸣声。

long);

  set("exits", ([ 
	  "north":__DIR__"changxiajie1",
	  "west":__DIR__"yizhan",
  	  "south":__DIR__"changxiajie3",
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

