
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小溪");
  set ("long", @LONG
这里是一条小溪。如果从这里坐上竹筏，可以顺流而下直到武夷山
下。溪水清澈，几乎可以映出你的容貌。经常有野兔等小动物在这里喝
水。
LONG);

  set("exits", ([ 

   "southwest":__DIR__"doupo1",
   "northdown":__DIR__"shanlu2",
   
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

