
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是条山路。这里树木环绕，环境幽雅，你深深吸了口气，顿觉
精神一爽。不时有大队的官兵从你的身旁走过，吓得路上的百姓都朝两
边闪去。
LONG);

  set("exits", ([ 

  "northwest":__DIR__"shanlu1",
  "southwest":__DIR__"shanlu3",
       ]));
  
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

