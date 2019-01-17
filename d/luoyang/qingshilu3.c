
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"青石路"NOR);
  set ("long", @LONG
这里是通往洛阳皇宫后宫的青石路。皇上每天上朝、退朝都要经过
这里，所以这里是皇宫的重地，朝廷都派重兵把守在这里。这里道路宽
敞，四周有许多花草。
LONG);

  set("exits", ([ 
  
  "north":__DIR__"beilang1",
  "east":__DIR__"zhiban-room",
  "south":__DIR__"houdian",
         ]));
  set("objects",([
	  __DIR__"npc/guanbing":4,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

