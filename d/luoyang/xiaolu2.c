
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是洛阳城南的郊区。从这里可以到洛阳的净念禅院。这里的人
很少。只有几个上香的人来往。
LONG);

  set("exits", ([ 
	  "east":__DIR__"xiaolu3",
	  "west":__DIR__"xiaolu1",
  
         ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

