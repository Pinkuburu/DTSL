
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","当铺");
  set ("long", @LONG
这里是洛阳的一家当铺。由于是战乱年代，所以来这里典卖东西的
人很多。当铺老板周先生坐在那里，盯着出入的人。
LONG);

  set("exits", ([ 
	  "east":__DIR__"baihujie4",
         ]));
  set("objects",([
	  __DIR__"npc/zhou":1,
	  ]));

 set("valid_startroom", 1);
  setup();
 
}

