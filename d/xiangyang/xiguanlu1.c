
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是襄阳城的西门了外的官路。东边就是襄阳的西门了。这里进
进出出只有很少的人。
LONG);

  set("exits", ([ 
 "east":__DIR__"ximen",
 "west":__DIR__"xiguanlu2",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

