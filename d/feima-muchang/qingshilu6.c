
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","青石路");
  set ("long", @LONG
这里是一条青石路。地上铺着整齐的方砖。由这里可以到大管家商
震的卧室。有几个丫鬟正从这里进出。
LONG);

  set("exits", ([ 
	  "east":__DIR__"feiniao_yuan",
	  "north":__DIR__"woshi2",
    ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

