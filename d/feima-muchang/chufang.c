
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","厨房");
  set ("long", @LONG
这里是飞马牧场的厨房。这里供应飞马牧场每天的饭食。只见几个
厨房火夫正在忙着准备饭食，这里香气四溢，你不禁流下了口水。
LONG);

  set("exits", ([ 
	  "north":__DIR__"caiyuan",
    ]));
 set("objects",([
    __DIR__"obj/niurou":3,
    __DIR__"obj/mantou":3,
    ]));
 
 set("resource/water",1);

  
  set("valid_startroom", 1);
  setup();
 
}

