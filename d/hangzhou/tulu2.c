
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里是条土路。这里已经走出了浙江的境地了，往西走就是江西的
境地了。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"tulu1",
 "west":__DIR__"shangang1",
        ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

