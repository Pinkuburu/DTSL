
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","广场");
  set ("long", @LONG
这里是阴癸派的广场。这里极其宽敞，正面有个高台，高台周围是
一些香炉等东西。广场的地面均是用上等的大理石铺成。每逢阴癸派有
什么大事，所有阴癸派的弟子都聚集在这里。这里平时很冷清。
LONG);
  set("exits",([
	  "south":__DIR__"huayuan",
	  "north":__DIR__"qingshilu1",
	  "east":__DIR__"qingshilu4",
	  "west":__DIR__"qingshilu3",
	  ]));
set("outdoors","yinkui");
  
  set("valid_startroom", 1);
  setup();
 
}

