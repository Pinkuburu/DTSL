
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西湖东岸");
  set ("long", @LONG
这里是西湖的东岸。这里停着几艘小船。有很多游客登船去领略西
湖的风光。这里碧波粼粼，景色秀丽，你不禁被深深的吸引住了。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"dongan1",
 "southwest":__DIR__"nanan1",
        ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

