
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是一条官路。南边就是成都的北门了。这里的行人渐渐多了起
来，有些热闹了。
LONG);

  set("exits", ([ 
  "northeast":__DIR__"guanlu3",
  "southwest":"/d/chengdu/dabeimen",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

