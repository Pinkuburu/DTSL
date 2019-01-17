
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","沙石路");
  set ("long", @LONG
这里是条沙石路。这里的天气渐渐好了起来。这里的行人也很多。
有很多人在往北边走。
LONG);

  set("exits", ([ 
 "south":__DIR__"shashilu2",
 "northeast":__DIR__"dalu1",
 "east":__DIR__"shangang",
        ]));
  set("objects",([
	  __DIR__"npc/shang":1,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

