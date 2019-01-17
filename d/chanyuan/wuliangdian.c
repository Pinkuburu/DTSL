
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","无量殿");
  set ("long", @LONG
这里是净念禅院的无量殿。这里有一尊铜铸普贤骑象的像。这里放
了一个大香炉，燃着的檀香木正送出大量香气，弥漫于整个殿内，不由
得让人心绪宁静，感染到出世的气氛。
LONG);

  set("exits", ([ 
	  "westdown":__DIR__"shijie2",
	  "eastup":__DIR__"shijie3",
  
         ]));
  set("objects",([
    __DIR__"npc/buchen":1,
    ]));
  set("valid_startroom", 1);
  setup();
 
}
