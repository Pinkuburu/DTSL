
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","包子铺");
  set ("long", @LONG
这间包子铺虽然不大，但是生意倒是非常的好，你找了一张空桌坐
了下来，店小二马上拿着一条白毛巾笑盈盈的向你走了过来。
LONG);

  set("exits", ([ 
 "east":__DIR__"xishixijie3",
        ]));
  set("objects",([
	  __DIR__"npc/xiaoer3":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

