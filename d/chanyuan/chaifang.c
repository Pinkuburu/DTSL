
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","柴房");
  set ("long", @LONG
这里是禅院的柴房。平时有和尚在这里做工。地上散乱地放着一些
锯子、斧头等东西，墙脚还堆着一些碎木渣。这里也是禅院弟子修行的
地方。
LONG);

  set("exits", ([ 
	  "southwest":__DIR__"xiaolu7",
      ]));

  
  set("valid_startroom", 1);
  setup();
 
}

