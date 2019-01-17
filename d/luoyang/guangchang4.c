
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"广场"NOR);
  set ("long", @LONG
再往北走就是大殿了。文武百官上朝之前都要在那里休息。两边是
龙盘的柱子，一看就是出自名家之作。皇宫戒备森严，很少看到有人走
过。
LONG);

  set("exits", ([ 
  "up":__DIR__"shijie1",
  "south":__DIR__"guangchang2",
         ]));

  set("objects",([
   __DIR__"npc/taijian1":2,
   ]));
   
  set("valid_startroom", 1);
  setup();
 
}

