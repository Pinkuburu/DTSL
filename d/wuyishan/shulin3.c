
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是一片茂密的树林。这里已经是树林的边缘。阳光猛地倾泻而
来，晃的你有些睁不开双眼。你用手遮住额头，发现东边是一个山峰，
南边还有一条山路。
LONG);

  set("exits", ([ 

   "east":__DIR__"shanfeng",
   "west":__DIR__"shulin2",
   "south":__DIR__"shanlu3",
   "north":"/d/clone/room/iron/room1",
  
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

