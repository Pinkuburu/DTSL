
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","大路");
  set ("long", @LONG
这里是个宽敞大路。这里的人已经很多了。虽然是战乱年代，但依
然不减江南应有的繁华景象。
LONG);

  set("exits", ([ 

  "east":__DIR__"dalu3",
  "west":__DIR__"dalu1",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

