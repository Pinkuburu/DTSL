
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是洛阳城的南门外的官路。西北就是洛阳城的南门了。这里的
行人渐渐多了起来。
LONG);

  set("exits", ([ 
 "northwest":"/d/luoyang/nanmen2",
 "southeast":__DIR__"guanlu2",
 
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

