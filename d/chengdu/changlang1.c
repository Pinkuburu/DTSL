
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长廊");
  set ("long", @LONG
这里是个长廊。北面有一座凉亭，南边是独尊堡的堡主解晖的卧室
了。有几个丫鬟从里面进进出出。
LONG);

  set("exits", ([ 
  
	  "north":__DIR__"liangting",
	  "south":__DIR__"woshi1",
        ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
