
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","包子店");
  set ("long", @LONG
这里是扬州城的最出名的一家包子店。这里的做的菜肉包子最为有
名。再加上专管卖包子的老冯的小妾贞嫂，生的花容月貌，更成了招揽
生意的活招牌。
LONG);

  set("exits", ([ 
 "west":__DIR__"nanjishi",
        ]));
  set("objects",([
	  __DIR__"npc/zhen":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

