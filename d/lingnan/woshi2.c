
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","卧室");
  set ("long", @LONG
这里是宋智的卧室。房间很整洁，看来是刚有人打扫过。床上的被
褥叠得整整齐齐。桌子上放着一副写好的书法，字迹看起来苍劲有力，
宛如剑锋。墙壁上挂着一把长剑。
LONG);

  set("exits", ([ 

  "west":__DIR__"liangting2",
      ]));
  set("objects",([
	  __DIR__"npc/songzhi":1,
	  ]));

  set("valid_startroom", 1);
  
  setup();
 
}

