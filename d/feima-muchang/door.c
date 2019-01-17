
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","内堡门口");
  set ("long", @LONG
这里是飞马牧场的内堡门口。不是飞马牧场的人，是不能够进去的。
有很多人牵着马朝外走去。远处可以看到几个牧场，有几个飞马牧场的弟
子正在那里放牧养马。不时有飞马牧场的人在这里进进出出。
LONG);

  set("exits", ([ 
  
	  "north":__DIR__"qingshilu1",
	  "southeast":__DIR__"caodi1",
         ]));
  set("objects",([
	  __DIR__"npc/dizi":1,
	  ]));
  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
"/obj/board/feima_b.c"->foo();
 
}

