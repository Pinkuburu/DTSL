
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是襄阳城的南门外的官路。这里的人不是很多了。这里的道路
非常宽敞，四周景色秀丽。不时有大队的官兵从你的身旁走过，领头的
将领不时回头打量着你。
LONG);

  set("exits", ([ 
 "north":__DIR__"nanmen",
 "south":__DIR__"guanlu4",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

