
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小径");
  set ("long", @LONG
这里是一条小径。俗话说“上有天堂，下有苏杭”，你不禁为周围
美丽景色所吸引了。
LONG);

  set("exits", ([ 

  "southwest":__DIR__"xiaojing1",
  "north":__DIR__"caodi1",
        ]));
 
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

