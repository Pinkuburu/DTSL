
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西廊");
  set ("long", @LONG
这里是西廊。墙壁上有各种美丽的图案，种类繁多，有山水、花鸟、
鱼虫等等，一看就是出自著名工匠之手。东面是独尊堡的主堂。
LONG);

  set("exits", ([ 
  
	  "east":__DIR__"zhutang",
	  "west":__DIR__"xilang2",
        ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
