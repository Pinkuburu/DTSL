
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长夏大街");
  set ("long", @long
这里是洛阳的长夏街。南面就是洛阳的长夏门了，而东边则是一间
药铺，不论高低贵贱都可以进去抓药。

long);

  set("exits", ([ 
	  "north":__DIR__"changxiajie4",
  	  "south":__DIR__"nanmen2",
  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

