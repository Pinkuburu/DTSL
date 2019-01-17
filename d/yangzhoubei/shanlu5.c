
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是条山路。南边可以看到五岳之首的泰山。北边是黄河的南岸，
这里可以听到滚滚的黄河声音。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"huanghenan",
 "southwest":__DIR__"taishanjiao",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

