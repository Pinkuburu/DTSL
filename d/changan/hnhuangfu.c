
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","海南晃府");
  set ("long", @LONG
这里是一片园林式的住宅区，规模宏大，房舍重重，而且风景秀丽，
鸟语花香。这里的建筑属于旧隋的建筑风格，且该是隋初建成，故在风
格与手法材料仍上承魏晋南北朝的遗风。自从晃公错投靠李渊后，李渊
就把这片住宅赏赐给了他们作为府第。
LONG);

  set("exits", ([ 
 "east":__DIR__"ahdajie4",
         ]));
  set("objects",([
         __DIR__"npc/baixing":2,
         ]));
  set("valid_startroom", 1);
  setup();
 
}
