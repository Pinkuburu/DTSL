
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里是一条土路。北边就是长江了，滔滔的江水不时拍上来。远远
望去，似乎有几叶轻舟行驶于江水之中。
LONG);

  set("exits", ([ 
	  "south":__DIR__"shilu",
	  "west":__DIR__"tulu2",
	  "east":__DIR__"bingqifang",
    ]));
set("outdoors","dajiang");
  /*set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));*/
  set("valid_startroom", 1);
  setup();
 
}