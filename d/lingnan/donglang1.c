
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","东廊");
  set ("long", @LONG
这里是东廊。西面是宋家堡的正厅了。长廊的墙壁上刻画着一些精
美的壁画，有山水、人物等。均是优秀工匠所做。不时有一些宋家堡弟
子从你的身旁匆匆走过。
LONG);

  set("exits", ([ 

  "west":__DIR__"zhengting",
  "east":__DIR__"donglang2",
       ]));
  set("objects",([
	  __DIR__"npc/songfaliang":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

