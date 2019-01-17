
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南大街");
  set ("long", @LONG
这里是襄阳的南街。往北走可以到襄阳的中心。东面有一家钱庄，
钱庄的金字招牌在这里就看得非常清楚。有几个官兵从你的身旁走过，
似乎正在谈论襄阳的钱独关，其中一个回头瞪了你一眼，然后又继续和
其他官兵谈笑去了。
LONG);

  set("exits", ([ 
 "east":__DIR__"qianzhuang",
 "north":__DIR__"nandajie2",
 "south":__DIR__"nandajie4",
        ]));
  set("objects",([
	  __DIR__"npc/zhongnian":1,
	  "/d/yinkui/npc/baiqinger":1,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

