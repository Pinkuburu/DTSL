
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","休息室");
  set ("long", @LONG
这里是大江联分舵的休息室。这里已经有很多大江联弟子在休息了。
你来到这里，不禁有些困了，不禁想睡上一觉。
LONG);

  set("exits", ([ 
	  "west":__DIR__"shalu",
	     ]));
set("sleep_room",1);
  /*set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));*/
  set("valid_startroom", 1);
  setup();
 
}

