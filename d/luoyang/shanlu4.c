
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条南下的山路。往南走就可以走下秦岭了。这里道路曲折
，你不禁小心起来。
LONG);

  set("exits", ([ 
  "northup":__DIR__"shanlu3",
  "westdown":__DIR__"shanlu5",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

