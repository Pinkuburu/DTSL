
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"无嗔堂"NOR);
  set ("long", @LONG
这里是慈航静斋的无嗔堂。佛家忌嗔，但是无嗔念也是最难修炼的。
慈航静斋的弟子要时刻来这里修炼，以达到真正的无嗔。
LONG);

  set("exits", ([ 

  "south":__DIR__"qusutang",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  
  set("valid_startroom", 1);
  setup();
 
}

