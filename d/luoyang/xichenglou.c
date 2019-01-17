
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"安国门楼"NOR);
  set ("long", @LONG
这里是横跨洛水的西门城楼，连接洛水两岸的城门，平时不准百姓
上来，只做为调动兵力的专用通道。
LONG);

  set("exits", ([ 
  

  "northdown":__DIR__"ximen",
  "southdown":__DIR__"xibianmen2",
         ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));

  set("valid_startroom", 1);
  setup();
 
}

