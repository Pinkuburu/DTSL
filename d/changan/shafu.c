
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","沙府");
  set ("long", @LONG
这里是一片豪华的府第，雕梁画栋，金壁辉煌，这里的主人是曾经
风光一时的洛阳首富－沙家，因为躲避战乱，全家迁居到这里来投靠李
渊。
LONG);

  set("exits", ([ 
 "west":__DIR__"asdajie4",
         ]));
set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}
