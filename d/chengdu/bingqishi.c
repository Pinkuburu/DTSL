
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","兵器室");
  set ("long", @LONG
这里是独尊堡的兵器室。这里放着很多兵器，如刀，剑等。有几个
铁匠正在那里打磨着兵器。几个独尊堡弟子正在旁边挑选着自己合手的
兵器。
LONG);

  set("exits", ([ 
	  "west":__DIR__"wuchang",
        ]));
  set("objects",([
	  __DIR__"obj/changjian":2,
	  __DIR__"obj/blade":2,
	  __DIR__"obj/chutou":2,
	  ]));
set("valid_startroom", 1);
  setup();
 
}
