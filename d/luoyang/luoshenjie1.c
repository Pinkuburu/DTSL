
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","洛神大街");
  set ("long", @LONG
这里是洛阳的洛神大街。这里已经很繁华了。在战乱时期，由于王
世充治城有方，所以洛阳相当的繁华。这里人来人往，再往东走，就可
以到天津桥了。
LONG);

  set("exits", ([ 
  
  "west":__DIR__"ximen",
  "east":__DIR__"luoshenjie2",
  "north":__DIR__"yanju",
         ]));
  set("objects",([
	  __DIR__"npc/old":1,
	  ]));
  set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

