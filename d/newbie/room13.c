
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","进阶篇");
  set ("long", @LONG
恭喜你！到了这里你快从大唐学院毕业了！这里将会将会教授一些
进阶性质的东西了！快到两旁的小屋去看看吧！
LONG);

  set("exits", ([ 
 "east":__DIR__"room14",
 "west":__DIR__"room15",
 "north":__DIR__"room16",
 "south":__DIR__"room10",
        ]));
  
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

