
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","青石路");
  set ("long", @LONG
这里是条青石路。地上铺着整齐的方砖。北面是场主和大管家的居
处。平常人等是不能来这里的。有几个丫鬟正从里面走出。
LONG);

  set("exits", ([ 
	  "south":__DIR__"qingshilu4",
	  "north":__DIR__"feiniao_yuan",
	  "east":"/d/clone/room/orgsaferoom/feima/wanxiaotang",
    ]));
 set("objects",([
	  __DIR__"npc/dizi":1,
	  ]));
  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

