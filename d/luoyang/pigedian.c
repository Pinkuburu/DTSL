
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","皮革店");
  set ("long", @long
一进到屋子里，你立刻感觉到一股让人恶心的气味扑鼻而来，没办
法，这就是处理皮革的过程中产生的气味。
long);

  set("exits", ([ 
      "north":__DIR__"luoshuidi1",
  ]));

  set("valid_startroom", 1);
  setup();
 
}

