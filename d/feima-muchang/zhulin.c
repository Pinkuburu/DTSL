
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"竹林"NOR);
  set ("long", @LONG
这里是竹林，这里幽静无声，给人一种舒适的感觉。西边是一个回
廊，东边是一个方厅。
LONG);

  set("exits", ([ 

	  "west":__DIR__"huilang4",
	  "east":__DIR__"fangting",
  ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

