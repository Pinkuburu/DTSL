
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","职业篇");
  set ("long", @LONG
做惯了大侠，想不想来个职业当当呢？在大唐中，你可以选择三种
职业：铁匠、药师、杀手。
具体的介绍请到两旁的屋子去看看吧！在大唐中是不能转换职业的，所
以选择职业时一定要慎重考虑！
LONG);

  set("exits", ([ 
 "east":__DIR__"room8",
 "west":__DIR__"room9",
 "north":__DIR__"room10",
 "south":__DIR__"room4",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

