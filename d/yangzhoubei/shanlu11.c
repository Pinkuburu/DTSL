
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。南边是一片树林。望北边走可以到泰山。这里是
通往安徽的道路。这里的行人不是很多。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu3",
 "southwest":__DIR__"shulin3",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

