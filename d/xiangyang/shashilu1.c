
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","沙石路");
  set ("long", @LONG
这里是条沙石路。大风吹来，只见漫天的黄沙，你不由蒙住了眼睛。
往南走可以到军事重地襄阳城。
LONG);

  set("exits", ([ 
 "southeast":__DIR__"beiguanlu2",
 "north":__DIR__"shashilu2",
 "northwest":__DIR__"shanqiu",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

