
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","草丛");
  set ("long", @LONG
这里是一片草丛。草高过人头，几乎分不出东南西北来。
LONG);

  set("exits",([
	  "west":__DIR__"door",
	  "southeast":__DIR__"caocong2",
	  "east":__DIR__"caocong1",

	  ]));
  set("outdoors","yinkui");
  set("valid_startroom", 1);
  setup();
 
}

