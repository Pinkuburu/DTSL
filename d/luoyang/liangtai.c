
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"凉台"NOR);
  set ("long", @LONG
这里是凉台。这里风景秀丽。这里已经是皇宫的内部了，所以有很
多的卫兵在来回的巡逻。凉台的下面是一个鱼池。有很多的金鲤鱼在游
来游去。有几个宫女正在池边玩耍。
LONG);

  set("exits", ([ 
  
  "north":__DIR__"qingong2",
  "west":__DIR__"donglang2",

         ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

