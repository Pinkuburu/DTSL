
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","丘陵");
  set ("long", @LONG
这里是巴陵城南的一片丘陵地，丘陵起伏不平，红褐色的岩石奇型
怪状，沙石路到这里逐渐隐没于丘陵之中，因为这附近有强人出没，行
人几乎都不到这里来。
LONG);

  set("exits", ([ 

  "southwest":__DIR__"qiuling5",
  "northeast":__DIR__"shashilu2",
       ]));

set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

