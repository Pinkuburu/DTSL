
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIM"卧室"NOR);
  set ("long", @LONG
这里是阴癸派弟子休息的地方。床上的被褥非常凌乱，两边的墙上
还挂着几幅春宫图。有几个弟子正在那里熟睡。你来到这里，不禁有些
困了。
LONG);
  set("exits",([
	  "north":__DIR__"lianwuchang",
	  ]));

  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

