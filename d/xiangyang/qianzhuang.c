
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","钱庄");
  set ("long", @LONG
这是襄阳城一家有名的钱庄。但是由于战乱，这里的生意并不是很
好。门口金字招牌反而招来了很多强盗。老板正在那里计算着账目，有
几个伙计正趴在桌子上打盹。
LONG);

  set("exits", ([ 
 "west":__DIR__"nandajie3",
        ]));
  set("objects",([
	  __DIR__"npc/shen":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

