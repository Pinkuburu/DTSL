
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","风味小居");
  set ("long", @LONG
这里是一家小吃店，这里的饭菜别具一格，吸引了很多人。只见门
口挂着一个大灯笼，上面写着四个大字：风味小居。门口还放着一个牌
子，写着每天的菜谱。店小二跑来跑去，忙个不停。
LONG);

  set("exits", ([ 
 "north":__DIR__"xidajie2",
        ]));
  set("objects",([
	  __DIR__"npc/xiaoer3":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

