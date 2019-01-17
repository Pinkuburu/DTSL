
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","延平门");
  set ("long", @LONG
这是长安城的延平门，城墙上贴着几张官府告示。官兵们警惕地注
视着过往行人，你最好小心为妙。一条笔直的青石板大道向东延伸。
LONG);

  set("exits", ([ 
 "east":__DIR__"xpdajie1",
 "north":__DIR__"xiaolu2",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

