
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","金天宫");
  set ("long", @LONG
金天宫大殿全为大片铁瓦，内塑有神像，院前大门边还建有钟鼓楼。
这里大片松林，枝高叶茂，中有古观庙宇，配上林间小道，景色非常优美。
在这里向四处观望，真是山恋起伏，苍苍莽莽。
LONG);

  set("exits", ([ 
 "westdown":__DIR__"yangtianchi",
 "southeast":__DIR__"shanlu4",
        ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
