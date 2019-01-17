
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是一条宽敞的官路。南边就是扬州的北门了。由于扬州自古都
是繁华的城市，所以这里渐渐热闹了起来。只见很多行人朝南边的北门
涌去。
LONG);

  set("exits", ([ 
 "north":__DIR__"guanlu3",
 "south":"/d/yangzhou/beimen",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

