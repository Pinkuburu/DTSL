
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIC"天津桥"NOR);
  set ("long", @long
天津桥乃是洛阳四大名桥之一，它也是洛阳繁华的一个标志。此桥
到处雕梁画栋，与周围的景色融合在一起，不愧是洛阳一景。
long);

  set("exits", ([ 
  

  "north":__DIR__"luoshenjie2",
  "southup":__DIR__"tianjinqiao2",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

