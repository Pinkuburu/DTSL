
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南天门");
  set ("long", @LONG
这里是泰山的南天门。这里便是泰山顶的入口处。从这里附视山下，
群山如龟伏地，河流如蚓缠绕，天地空阔，无可名状。
LONG);

  set("exits", ([ 

 "eastdown":__DIR__"bixiaci",
 "enter":"/d/job/haishajob/shandong1",
          ]));

set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

