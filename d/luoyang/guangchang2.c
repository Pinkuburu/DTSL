
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"广场"NOR);
  set ("long", @LONG
这里是殿前广场，通往皇宫的正殿。这里几乎没有什么人来往。平
时有士兵在这里巡逻。再往北走就是大殿了。两边是龙盘的柱子，一看
就是出自名家之作。皇宫戒备森严，很少看到有人走过。
LONG);

  set("exits", ([ 
  "north":__DIR__"guangchang4",
  "west":__DIR__"guangchang1",
  "east":__DIR__"guangchang3",
  "south":__DIR__"door",
         ]));
  set("objects",([
   __DIR__"npc/guanbing":2,
   ]));
  
  set("valid_startroom", 1);
  setup();
 
}

