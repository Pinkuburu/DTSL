
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","天街");
  set ("long", @long
这里是天街，中间是皇帝出巡的御道，道路两边则种植了许多品种
的树木，天宽地阔，确有一番王者风范。
long);

  set("exits", ([   
      "south":__DIR__"tianjie2",
      "north":__DIR__"beijie1",
      "east":__DIR__"chaixinpu"
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

