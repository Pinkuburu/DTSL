
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路。北面是秦岭，这里的道路有些宽敞了。南边有一
片树林，看起来非常茂密。
LONG);

  set("exits", ([ 
  "north":__DIR__"shanlu5",
  "southwest":__DIR__"shulin1",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

