
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","大路");
  set ("long", @LONG
这里是一条宽敞的大路。南边就是合肥的北门了。这里可以听到里
面热闹的声音。这里的行人也多了起来。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"dalu1",
 "south":"/d/hefei/beimen",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

