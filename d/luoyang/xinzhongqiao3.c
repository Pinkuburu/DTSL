
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIC"新中桥"NOR);
  set ("long", @long
新中桥乃是洛阳四大名桥之一，它横跨洛水，其名本意是新朝中兴
之意，现在看来，不过是对杨广残暴统治的一个讽刺而已。
long);

  set("exits", ([ 
  

  "northup":__DIR__"xinzhongqiao2",
  "south":__DIR__"tianjie3",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

