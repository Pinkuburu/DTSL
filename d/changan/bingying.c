
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","兵营");
  set ("long", @LONG
这里是长安御林军的兵营，官兵们在武将的指挥下列队操练，尽管
这么多年没有战事，官兵们还是在认真的排阵，士兵们不敢有任何松懈。
这里可不是闲杂人等来的地方，你最好还是赶快离开。
LONG);

  set("exits", ([ 
 "east":__DIR__"csdajie2",
       ]));
  set("objects",([
	  __DIR__"npc/bing2":2,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

