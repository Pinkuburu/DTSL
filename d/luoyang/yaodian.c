
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","药店");
  set ("long", @LONG
这里是一家药店。由于战乱连年，所以这里的生意很好。这里的药
物种类齐全，在洛阳城享有很高的声誉。
LONG);

  set("exits", ([ 
 "west":__DIR__"changxiajie4",
        ]));
 set("objects",([
	 __DIR__"npc/wangdaifu":1,
	 ]));
 set("valid_startroom", 1);
  setup();
 
}

