
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"苦心房"NOR);
  set ("long", @LONG
这里是慈航静斋的苦心房。慈航静斋的弟子都要经过苦心的的修行，
忘掉一切世俗之念，所以这里也是慈航静斋修炼心神的地方。
LONG);

  set("exits", ([ 

  "south":__DIR__"zoulang1",
    ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/

  
  set("valid_startroom", 1);
  setup();
 
}

