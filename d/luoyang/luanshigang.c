
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","乱石岗");
  set ("long", @LONG
这里是乱石岗。由于没有很少有人来这里，所以显得的有些荒凉。
据说这里经常有强盗出没，你不禁小心起来。
LONG);

  set("exits", ([ 
"southeast":__DIR__"shanlu1",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

