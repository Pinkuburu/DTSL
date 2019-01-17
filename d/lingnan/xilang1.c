
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","西廊");
  set ("long", @LONG
这里是西廊。东面是宋家堡的正厅。长廊的墙壁上刻画着一些精美
的壁画，种类繁多，有山水、人物等。均是优秀工匠所做。不时有一些
宋家堡弟子从你的身旁匆匆走过。
LONG);

  set("exits", ([ 

  "east":__DIR__"zhengting",
  "west":__DIR__"xilang2",
       ]));
  set("objects",([
	  __DIR__"npc/yahuan":1,
	  ]));
  set("objects",([
	  "/d/clone/npc/liu":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

