
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","迷宫");
  set ("long", @LONG
这里是一个迷宫，道路错综复杂，而且光线不足，非常容易迷路。
地上有一些残骸尸骨，看来是困死在迷宫中的人留下的。
LONG);

  set("exits", ([ 
 "east":__DIR__"migong2",
 "west":__DIR__"migong4",
 "south":__DIR__"migong1",
 "north":__DIR__"migong3",
        ]));  
  set("valid_startroom", 1);
  setup();
 
}

