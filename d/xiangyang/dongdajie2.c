
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东大街");
  set ("long", @LONG
这里是襄阳的东街。西面可以到襄阳的中心。北面是一家书铺。书
铺的招牌已经很破旧了，上面的“记学储实”四个已经变得模糊不清。
如今武功更容易保住性命，所以去书铺的人越来越少了。
LONG);

  set("exits", ([ 
 "east":__DIR__"dongdajie3",
 "south":__DIR__"dangpu",
 "south":__DIR__"dangpu",
 "west":__DIR__"dongdajie1",
 "north":__DIR__"shupu",
        ]));
  set("objects",([
	  __DIR__"npc/boy":1,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

