
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是山路。抬头望去，泰山的顶峰还是在云雾中。前面就是泰山
的红门宫了。不时有游人从你的身旁走过。
LONG);

  set("exits", ([ 

   "eastdown":__DIR__"shanlu1",
   "up":__DIR__"hongmengong",
          ]));
 /*set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

