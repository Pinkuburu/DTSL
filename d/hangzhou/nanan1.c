
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西湖南岸");
  set ("long", @LONG
这里是西湖的南岸。从这里看去，西湖宛如一面镜子铺在地上，晶
莹剔透。清风吹过，湖面泛起阵阵微波，又宛如碧绿的飘带一般。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"dongan3",
 "west":__DIR__"nanan2",
        ]));
  set("objects",([
	  __DIR__"npc/shangren":1,
	  ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

