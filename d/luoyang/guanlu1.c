
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是洛阳南门的官路。虽然近来兵荒马乱，但是这条官路还是很
安全。北面就是洛阳城了。
LONG);

  set("exits", ([ 
  "north":__DIR__"baihumen",
  "southwest":__DIR__"guanlu2",

         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

