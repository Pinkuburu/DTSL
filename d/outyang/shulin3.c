
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是一片树林，树木茂盛，遮住了大部分阳光。清新的空气扑鼻
而来，你觉得精神一振。看样子这里很少有人来，你不禁小心起来。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shulin2",
 "southeast":__DIR__"xiaolu1",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

