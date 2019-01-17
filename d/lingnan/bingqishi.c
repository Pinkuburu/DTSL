
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","兵器室");
  set ("long", @LONG
这里是宋家堡的兵器室。地上散乱地放着一些兵器，旁边还有几个
工人正在那里用力地打磨着兵器。有几个宋家堡的弟子正在旁边挑选着
自己合手的兵器。
LONG);

  set("exits", ([ 

   "west":__DIR__"wuchang",
     ]));
  set("objects",([
	  __DIR__"obj/blade":3,
	  __DIR__"obj/guai":3,
	  ]));

  set("valid_startroom", 1);
  setup();
 
}

