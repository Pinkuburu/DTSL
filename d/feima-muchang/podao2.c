
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","宽敞坡道");
  set ("long", @LONG
这里是个宽敞的坡道，这里已经是飞马牧场的外堡了。这里人渐渐
多了起来。有很多人牵着马朝外走去。远处可以看到几个牧场，有几个
飞马牧场的弟子正在那里放牧养马。
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"xiaolu1",
	  "southeast":__DIR__"podao1",
         ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

