
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","休息室");
  set ("long", @LONG
这里是海沙帮的休息室。这里鼾声阵天，不时有海沙帮的人进来休
息。你来到这里，也不禁有些困了。
LONG);

  set("exits", ([ 

  "north":__DIR__"xiaolu4",
        ]));
  set("sleep_room",1);
  
  set("valid_startroom", 1);
  setup();
 
}

