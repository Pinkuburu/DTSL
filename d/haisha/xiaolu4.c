
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是渔村的内的一条小路。这里静悄悄的。没有很大的声响。偶
尔只能听见海浪排击的声音。
LONG);

  set("exits", ([ 

  "north":__DIR__"xiaolu2",
  "south":__DIR__"xiuxishi",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

