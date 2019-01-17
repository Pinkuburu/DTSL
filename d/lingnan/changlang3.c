
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","长廊");
  set ("long", @LONG
这里是个长廊。北边是宋家堡的正厅。南边是个花园。长廊的墙壁
上刻画着一些精美的壁画，种类繁多，有山水、人物等。均是优秀工匠
所做。不时有一些宋家堡弟子从你的身旁匆匆走过。
LONG);

  set("exits", ([ 

  "northeast":__DIR__"zhengting",
  "south":__DIR__"huayuan1",
       ]));
  set("objects",([
	  "/d/clone/npc/wangzhongxuan":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

