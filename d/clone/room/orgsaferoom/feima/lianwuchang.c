
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","练武场");
  set ("long", @LONG
这里是飞马牧场的练武场，只见这里兵器齐备，还有梅花桩、沙坑
等练武的东西。有几个飞马牧场弟子正在那里练习武艺，呼喝的声音不
住的传来。
LONG);

  set("exits", ([ 
 "south":__DIR__"huayuan",
 "east":__DIR__"lianwuchang2",
 "west":__DIR__"lianwuchang3",
 "north":__DIR__"lianwuchang4",
      ]));
  set("valid_startroom", 1);
  set("outdoors","feima");
  setup();
 
}
