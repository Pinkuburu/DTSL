#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short","官路");
  set ("long", @LONG
这里是一条官路。东边就是洛阳的西门了。这里的行人比较多了，
由于王世充近来治理有方，所以来投靠他的人很多。这里几乎可以听到
城内繁华的声音。
LONG);

  set("exits", ([ 
"west":__DIR__"lguanlu1",
"east":"/d/luoyang/ximen",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

