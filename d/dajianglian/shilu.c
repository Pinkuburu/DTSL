
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","石路");
  set ("long", @LONG
这里是一石路。不时有几个人和你擦肩而过。一阵风吹来，带了一
阵江水的气息，偶尔还可以听到船夫的声音。
LONG);

  set("exits", ([ 
	  "north":__DIR__"tulu1",
	  "south":__DIR__"caodi",
	  "west":__DIR__"juyitang",
	  "east":__DIR__"shalu",
    ]));
set("outdoors","dajiang");
  /*set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));*/
  set("valid_startroom", 1);
  setup();
 
}

