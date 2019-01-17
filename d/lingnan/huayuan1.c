
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","花园");
  set ("long", @LONG
这里是个花园。这里种植了各种花草，看起来五彩缤纷，赏心悦目。
群花争奇斗艳，竟相开放。有几个花匠正在这里修剪着花草。
LONG);

  set("exits", ([ 

  "north":__DIR__"changlang3",
  "west":__DIR__"xiaoqiao2",
  "southwest":__DIR__"xiaoqiao1",
       ]));
  set("objects",([
	  __DIR__"npc/yahuan":1,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

