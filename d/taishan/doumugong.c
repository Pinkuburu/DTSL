
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","斗母宫");
  set ("long", @LONG
这里是泰山的斗母宫。向下望去，还有很多游人在往上攀登，山下
的人看起来已经犹如蚂蚁一样了。
LONG);

  set("exits", ([ 

   "northup":__DIR__"hutiange",
   "southdown":__DIR__"shanlu3",
          ]));

set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

