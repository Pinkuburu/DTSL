
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","通远大街");
  set ("long", @LONG
你走在通远大街上，这条大街横贯长安城东西，东连通化门，西至
开远门，是长安城的主干道之一。南北通向的大街是望仙大街。
LONG);

  set("exits", ([
  "south":__DIR__"wxdajie3",
 "east":__DIR__"tydajie8",
 "west":__DIR__"tydajie6",
        ]));
  set("objects",([
   __DIR__"npc/dipi":1,
   __DIR__"npc/liumang":1,
   ]));
   
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

