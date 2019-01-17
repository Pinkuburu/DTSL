
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南大街");
  set ("long", @LONG
这里是襄阳的南大街。东面有一家酒楼，里面不时传来喝酒叫骂的
声音，吵得人耳烦心燥。有几个醉汉从你的身边摇摇晃晃走过，嘴里不
知道在嘀咕着什么。西面是襄阳的车马行，有几个官兵正朝那里走去。
LONG);

  set("exits", ([ 
 "west":__DIR__"chemahang",
 "north":__DIR__"nandajie1",
 "south":__DIR__"nandajie3",
 "east":__DIR__"jiulou",
        ]));
  set("objects",([
	  __DIR__"npc/shangren":1,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

