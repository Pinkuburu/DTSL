
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山洞");
  set ("long", @LONG
这里是一个山洞。里面黑乎乎的，伸手不见五指。似乎有什么声音，
你不禁加倍小心起来。
LONG);

  set("exits", ([ 

   "southwest":__DIR__"shandong1",
            ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

