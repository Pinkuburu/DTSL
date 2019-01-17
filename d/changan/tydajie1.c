
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","通远大街");
  set ("long", @LONG
你走在通远大街上，这条大街横贯长安城东西，东连通化门，西至
开远门，是长安城的主干道之一。四面静悄悄的。南北通向的大街是和
光大街。
LONG);

  set("exits", ([
 "north":__DIR__"tongxingshe",
 "south":__DIR__"hgdajie3",
 "eastup":__DIR__"tyqiao",
 "west":__DIR__"kaiyuanmen",
        ]));
  set("objects",([
         __DIR__"npc/dipi":1,
         ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

