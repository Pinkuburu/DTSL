
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是条官路。南边就是襄阳的北门了。这里有来来往往的几个行
人。
LONG);

  set("exits", ([ 
 "south":__DIR__"beimen",
 "north":__DIR__"beiguanlu2",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

