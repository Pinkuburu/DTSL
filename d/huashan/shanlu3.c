
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
北边为华山的南天门，这里道路崎岖，行人都是分外小心。在往南
边走，就可以到达华山的全真崖。
LONG);

  set("exits", ([ 
 "southwest":__DIR__"quanzhenya",
 "east":__DIR__"shanlu2",
       ]));
  /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
