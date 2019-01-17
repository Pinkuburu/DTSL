
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","石砌照壁");
  set ("long", @LONG
这里是一个石砌照壁。墙壁上有各种美丽的图案，种类繁多，有山
水、花鸟、鱼虫等等，一看就是出自著名工匠之手。照壁的大理石也是
少有的珍品。
LONG);

  set("exits", ([ 
  
	  "south":__DIR__"paifang",
	  "north":__DIR__"neibao",
	
         ]));
  set("objects",([
	  __DIR__"npc/fangyimin":1,
	  ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
