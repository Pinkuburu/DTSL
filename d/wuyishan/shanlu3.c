
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。北边是一片树林。东边有一个山洞，里面黑黝黝
的，不知道有没有危险。
LONG);

  set("exits", ([ 

   "east":__DIR__"shandong",
   "north":__DIR__"shulin3",
   "southwest":__DIR__"shanlu5",
   "southeast":__DIR__"shanlu4",
  
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

