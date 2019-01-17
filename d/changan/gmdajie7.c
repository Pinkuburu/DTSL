#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","光明大街");
  set ("long", @LONG
你走在光明大街上，这条大街横贯长安城东西，东连春明门，西至
金光门，是长安城的主干道之一。四面静悄悄的。从这里南北通向的大
街是和光大街。
LONG);

  set("exits", ([ 
 "north":__DIR__"hgdajie2",
 "south":__DIR__"xishixikou1",
 "east":__DIR__"xishibeikou1",
 "west":__DIR__"ximen",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}


