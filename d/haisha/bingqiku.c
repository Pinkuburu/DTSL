
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","兵器库");
  set ("long", @LONG
这里是海沙帮的兵器库了，这里放着各种各样的兵器。刀、剑散乱
地摆放了一地，看来海沙帮近来又有大生意了。
LONG);

  set("exits", ([ 

  "southwest":__DIR__"caodi1",
         ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  set("valid_startroom", 1);
  setup();
 
}

