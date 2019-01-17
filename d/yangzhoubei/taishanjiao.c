
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","泰山脚下");
  set ("long", @LONG
这里是泰山的山脚。抬头望去，泰山高耸的山峰深入云端，不时有
游人从你的身旁走过。你心中不禁生出一股豪情，要攀登泰山一番。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu5",
 "south":__DIR__"shanlu4",
 "west":"/d/taishan/daizongfang",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

