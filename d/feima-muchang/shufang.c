
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","书房");
  set ("long", @LONG
室内布置一式红木家具、桌上放着文房四宝，靠壁的柜架满是古玩
摆设，在宫灯映照下，墙的一壁还挂着一副对联，上书“五伦之中自有
乐趣；六经以外别无文章。”
LONG);

  set("exits", ([ 
	  "west":__DIR__"feiniao_yuan",
    ]));

  set("objects",([
	  __DIR__"npc/shangxiu-xun":1,
	  ]));
set("no_clean_up",1);
  set("valid_startroom", 1);
  setup();
 
}

