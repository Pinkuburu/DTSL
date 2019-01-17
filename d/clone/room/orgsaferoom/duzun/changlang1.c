
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","长廊");
  set ("long", @LONG
这里是一条长廊，两边画着一些精美的山水画。这里是独尊堡英雄
们练习武艺和休息的地方。北边是一个练武场，南边是一个厨房。不时
有独尊堡弟子从这里走过。
LONG);

  set("exits", ([ 
 "out":__DIR__"duzuntang",
 "northdown":__DIR__"lianwuchang",
 "southdown":__DIR__"chufang",
 "northwest":__DIR__"changlang2",
      ]));
  set("valid_startroom", 1);
 
  setup();
 
}
