
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIB"地道"NOR);
  set ("long", @LONG
这里是一个地道，黑黑的，伸手不见五指。一阵阵的冷风从里面吹
了出来，更显的阴森恐怖。
LONG);

  set("exits", ([ 
 "north":__DIR__"didao2",
"out":__DIR__"zhenbaozhai",
      ]));
  set("no_select",1);
  set("valid_startroom", 1);
  setup();
 
}
