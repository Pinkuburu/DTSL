
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","洛神大街");
  set ("long", @LONG
这里是洛阳的洛神大街。北面是洛阳人坊。从这里往南走可以到天
津桥。再往东走就是洛阳的中心了。
LONG);

  set("exits", ([ 
  

  "north":__DIR__"qinglongjie1",
  "east":__DIR__"luoshenjie3",
  "west":__DIR__"luoshenjie1",
  "south":__DIR__"tianjinqiao1",
         ]));
  /*set("objects",([
	  "/d/clone/npc/dugu-sheng":1,
	  ]));*/
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

