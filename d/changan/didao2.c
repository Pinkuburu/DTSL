
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIB"地道"NOR);
  set ("long", @LONG
这里是一个地道，黑黑的，伸手不见五指。前面好象有点亮光。突
然一只老鼠从你的身旁窜过。
LONG);

  set("exits", ([ 
 "east":__DIR__"didao3",
"south":__DIR__"didao1",
      ]));
  set("no_select",1);
  set("valid_startroom", 1);
  setup();
 
}
