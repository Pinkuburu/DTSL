
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIY"东城楼"NOR);
  set ("long", @LONG
这里是洛阳皇城的东城楼，是皇宫的防御性建筑。
LONG);

  set("exits", ([ 
  "northdown":__DIR__"eastdoor",
         ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));

  set("valid_startroom", 1);
  setup();
 
}

