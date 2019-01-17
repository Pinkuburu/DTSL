
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"长廊"NOR);
  set ("long", @LONG
这里是一条长廊。这里已经是皇宫的内部了，所以有很多的卫兵在
来回的巡逻。长廊的旁边有一个水池，水面清晰，可以看到里面有许多
鱼在游动。有几个宫女正在池边玩耍。
LONG);

  set("exits", ([ 
  
  "east":__DIR__"donglang1",
  "west":__DIR__"xilang1",
  "north":__DIR__"jiashan",
  "south":__DIR__"beilang1",
         ]));

  set("objects",([
   __DIR__"npc/gongnv1":1,
   ]));
  set("valid_startroom", 1);
  setup();
 
}

