
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","大路");
  set ("long", @LONG
这里是条宽敞大路。北边就是洛阳的南门了。这里几乎可以听到城
内热闹的声音。
LONG);

  set("exits", ([ 
 "south":__DIR__"dalu1",
 "north":"/d/luoyang/nanmen",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

