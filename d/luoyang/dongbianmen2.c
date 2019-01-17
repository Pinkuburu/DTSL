
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"立秋门"NOR);
  set ("long", @LONG
这里是洛阳的东门的边门。有几个官兵正在这里检查着来往的行人
。旁边还有一个军官在那里指手画脚，神气十足。
LONG);

  set("exits", ([ 
	
    "west":__DIR__"shennvdi3",
    "northup":__DIR__"dongchenglou",
 	
  ]));
	
  set("objects",([

    __DIR__"npc/bing":1,

  ]));

  set("outdoors","luoyang");

  set("valid_startroom", 1);

  setup();

}