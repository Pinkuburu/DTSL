
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山洞");
  set ("long", @LONG
这里是一个山洞。里面黑乎乎的，伸手不见五指。不时有蝙蝠从里
面飞出。你不禁小心起来。
LONG);

  set("exits", ([ 

   "out":__DIR__"shanlu2",
   "northeast":__DIR__"shandong2",
   "east":__DIR__"shandong3",
         ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

