
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长白山脚下");
  set ("long", @LONG
这里是长白山脚下。抬头望去，长白山一半是碧绿如脚下，一半是
白雪覆盖。隐隐约约可以看到，山上似乎有一座庙宇。
LONG);

  set("exits", ([ 
 "eastup":"/d/changbaishan/shanlu1",
 "west":__DIR__"shulin2",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

