
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山脚");
  set ("long", @LONG
这里是武夷山的山脚下了。抬头望去，武夷山翠绿的山色尽
收眼底。耳边不时传来飞鸟的鸣叫之声。有几个游人从你的身旁
走过，看来是去山上游玩的。这里还立着一个大石碑，上面写着
三个大字：武夷山。
LONG);

  set("exits", ([ 

   "southup":__DIR__"shanlu1",
   "northwest":"/d/dongming/xiaolu2",
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

