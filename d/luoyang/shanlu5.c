
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条南下的山路。往南走就可以走下秦岭了。这里的道路渐
渐宽敞起来了。
LONG);

  set("exits", ([ 
  "eastup":__DIR__"shanlu4",
  "south":__DIR__"xiaolu8",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

