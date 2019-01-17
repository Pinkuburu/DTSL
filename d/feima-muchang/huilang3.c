
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"回廊"NOR);
  set ("long", @LONG
这里是条回廊。两边的墙壁上刻画着很多山水的画，一看就知道必
是高明的工匠所做。回廊曲折连环，看似简单，但实则暗藏了机关之术，
进来的人似乎很难出去了。
LONG);

  set("exits", ([ 
	  "east":__DIR__"huilang"+(1+random(1)),
	  "south":__DIR__"huilang"+(1+random(5)),
	  "north":__DIR__"huilang"+(1+random(6)),
	  "west":__DIR__"huilang"+(1+random(4)),
   ]));

  
  set("valid_startroom", 1);
  setup();
 
}

void reset()
{
   
  set("exits", ([ 
	  "east":__DIR__"huilang"+(1+random(1)),
	  "south":__DIR__"huilang"+(1+random(5)),
	  "north":__DIR__"huilang"+(1+random(6)),
	  "west":__DIR__"huilang"+(1+random(4)),
   ]));
}