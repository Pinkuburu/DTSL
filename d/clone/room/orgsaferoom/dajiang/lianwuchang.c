
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","练武场");
  set ("long", @LONG
这里是大江联的练武场，只见这里兵器齐备，还有梅花桩、沙坑等
练武的东西。有几个大江联弟子正在那里练习武艺，呼喝的声音不住的
传来。
LONG);

  set("exits", ([ 
 "eastup":__DIR__"suishilu",
 "north":__DIR__"lianwuchang2",
 "west":__DIR__"lianwuchang3",
 "south":__DIR__"lianwuchang4",
      ]));
  set("valid_startroom", 1);
  set("outdoors","dajianglian");
  setup();
 
}
