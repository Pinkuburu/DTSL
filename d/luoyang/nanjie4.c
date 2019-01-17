
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南天街");
  set ("long", @LONG
这里是洛阳的南天街。南面就是洛阳的南门了。这里也有很多小商
贩在叫卖。这里的行人不是很多，只见南边官兵正严密的检查来往的行
人。
LONG);

  set("exits", ([ 
  "north":__DIR__"nanjie3",
  "south":__DIR__"nanmen",
  "east":__DIR__"pingfu_laodian",
  "west":__DIR__"ygrestroom1",
         ]));
  set("objects",([
     "/d/yinkui/npc/danmei":1,
     ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}


