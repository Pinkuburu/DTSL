
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","酒仓");
  set ("long", @LONG
这是位于城西南永阳里的一处酒仓，这里平日是运货送货的人车络
绎于途，今天由于没有人工作，反比平时更冷清。此仓建在永阳里中央
处，有大小四座建筑物，以高墙围绕。 
LONG);

  set("exits", ([ 

  "north":__DIR__"xpdajie1",

         ]));
  set("objects",([
         __DIR__"npc/jiubao":2,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

