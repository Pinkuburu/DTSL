
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里片草地。南边是黄河的北岸。在望东北走，就是海滨了。阵阵
风吹来，带来一股咸涩的气息。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"haibin1",
 "southwest":__DIR__"huanghebei",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

