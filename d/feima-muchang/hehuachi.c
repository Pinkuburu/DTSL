
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"荷花池"NOR);
  set ("long", @LONG
这里是个荷花池。正所谓「小荷才露尖尖脚」，这里的景色让人流
连忘返。四周的假山错落有致，看起来别具一格，不落俗套。
LONG);

  set("exits", ([ 
	  "south":__DIR__"huayuan2",
	  "northeast":__DIR__"ting",
    ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

