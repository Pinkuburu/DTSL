
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","洛阳木坊");
  set ("long", @LONG
这里是洛阳的闹市。钟鼓楼在这里遥遥相望。再往南走就是白虎桥
。这里人来人往，热闹非凡。
LONG);

  set("exits", ([ 
  

  "north":__DIR__"baihujie1",
  "southeast":__DIR__"baihujie3",
  "east":__DIR__"kedian",
  "west":__DIR__"zhonggulou",
         ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

