
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","悬崖");
  set ("long", @LONG
这里是一个悬崖。从这里可以看到下面的水潭。你向下看了看，觉
得有些眼晕，不由得晃了晃。
LONG);

  set("exits", ([ 
 "north":__DIR__"shanya",
 "east":__DIR__"shulin",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

