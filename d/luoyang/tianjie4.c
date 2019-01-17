
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","天街");
  set ("long", @long
这里是天街，中间是皇帝出巡的御道，道路两边则种植了许多品种
的树木，天宽地阔，确有一番王者风范。西面则是著名的董家酒楼。
long);

  set("exits", ([   
      "south":__DIR__"nanjie1",
      "north":__DIR__"tianjie3",
      "west":__DIR__"dongjia-jiulou",
  ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

