
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","大道");
  set ("long", @LONG
这里是一条大路。西南方可以到古城长安，路上行人不是很多，三
三两两的，似乎都很惬意的向北而行，看来哪里一定有什么风景名胜所
在。
LONG);

  set("exits", ([ 
 "northeast":"/d/taiyuan/road8b",
 "southwest":__DIR__"dadao1",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

