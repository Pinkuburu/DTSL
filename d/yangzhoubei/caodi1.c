
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里片草地。向北边望去，可以看到一个湖。草地柔软，走起路来
十分舒服。
LONG);

  set("exits", ([ 
 "north":__DIR__"gaoyouhu",
 "southeast":__DIR__"xiaolu2",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

