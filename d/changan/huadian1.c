
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","鲜花店");
  set ("long", @LONG
你一到这里，立即被一阵花香陶醉，只见从房顶到地面，全是花的
世界。从店里标签上的花名来看，大部分都是的当地的名花。卖花的姑
娘见你走了进来，忙面带笑容的迎了上来。
LONG);

  set("exits", ([ 
 "east":__DIR__"xishixijie5",
        ]));
  set("objects",([
	  __DIR__"npc/guniang":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

