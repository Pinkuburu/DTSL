
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","长廊");
  set ("long", @LONG
这里是一道长廊。廊壁上雕刻了各种山水花鸟，栩栩如生。一看手
笔就知道是出自名家工匠之手。宋家堡富甲天下，自然要请得天下最好
的工匠了。
LONG);

  set("exits", ([ 

  "out":__DIR__"door",
  "south":__DIR__"changlang2",
        ]));
  
  set("objects",([
     "/d/job/sjbzahuo/song":1,
     ]));
  
  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

