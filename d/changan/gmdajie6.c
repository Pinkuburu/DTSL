
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","光明大街");
  set ("long", @LONG
你走在光明大街上，这条大街横贯长安城东西，东连春明门，西至
金光门，是长安城的主干道之一。南北通向的大街是永安大街。
LONG);

  set("exits", ([ 
 "north":__DIR__"yadajie2",
 "south":__DIR__"xishidongkou1",
 "east":__DIR__"gmdajie5",
 "westup":__DIR__"gmqiao",
        ]));
   set("objects",([
	  __DIR__"npc/qinshubao":1,
	  ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

