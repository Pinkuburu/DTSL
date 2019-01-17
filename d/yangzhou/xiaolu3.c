
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路。西边可以遥遥望见合肥的城墙。这里的行人比较
多了，不是有人骑着马从你身旁驰过。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"xiaolu2",
 "west":"/d/hefei/dongmen",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

