
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"西门"NOR);
  set ("long", @LONG
这里是襄阳城的西门了。由于襄阳在地理上占有很重要的位置，所
以入城的检查也是非常严格。
LONG);

  set("exits", ([ 
 "east":__DIR__"xidajie1",
 "west":__DIR__"xiguanlu1",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

