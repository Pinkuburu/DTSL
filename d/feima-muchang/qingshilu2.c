
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","青石路");
  set ("long", @LONG
这里是一条青石路。这里人非常多，吵吵嚷嚷，非常热闹。有很多
人牵着马朝外走去。远处可以看到几个牧场，有几个飞马牧场的弟子正
在那里放牧养马。北边是一个园林。
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"yuanlin",
	  "south":__DIR__"qingshilu1",
         ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

