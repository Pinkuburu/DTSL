
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","御用码头");
  set ("long", @long
这个码头位于皇宫附近，是当年杨广出巡的时候建设的，专门供给
皇帝使用。不过现在已经是个公共码头，由洛阳官府掌管。
long);

  set("exits", ([ 
      "north":__DIR__"xiangwangjie3",
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

