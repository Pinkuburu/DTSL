
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"北廊"NOR);
  set ("long", @LONG
这里是北廊。再往北走就是皇帝的寝宫了。所以平常的人是不能再
走了。这里非常寂静，四周有许多树木、花草，带来阵阵的清香。不时
有太监进去给皇上通报事情。
LONG);

  set("exits", ([ 
  
  "north":__DIR__"changlang",
  "south":__DIR__"qingshilu3",

         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

