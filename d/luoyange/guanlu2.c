
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是条官路，这里已经远离了洛阳。但是行人还是很多。据说东
面的堰师是飞马牧场的领地，由于飞马牧场的马匹都是上乘，所以去买
马匹的人很多。
LONG);

  set("exits", ([ 
  "northwest":__DIR__"guanlu1",
  "east":__DIR__"xiaolu1",
        ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

