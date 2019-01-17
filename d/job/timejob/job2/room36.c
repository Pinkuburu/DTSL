
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","地下迷宫");
  set ("long", @LONG
这里是一个地下迷宫，看起来道路四通八达，非常容易迷路。
四周的墙壁上刻了许多奇怪的图案。这里黑洞洞的，伸手不见五
指，你不禁小心起来。
LONG);

  set("exits", ([ 
 "out":__DIR__"door",
        ]));
  set("no_quit",1);
 
  setup();
 
}

#include "room.c"