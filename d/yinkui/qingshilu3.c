
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","青石路");
  set ("long", @LONG
这里是条青石路。这里冷冷清清的。几乎没有什么人。东边是阴癸
派的议事广场。西边是阴癸派的练武场，那里不时传来阵阵的吆喝声。
LONG);
  set("exits",([
	  "east":__DIR__"guangchang",
	  "west":__DIR__"lianwuchang",
	  ]));

  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

