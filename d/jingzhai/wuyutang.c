
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"无欲堂"NOR);
  set ("long", @LONG
这里是慈航静斋的无欲堂。正所谓无欲则刚，但无欲又谈何容易。
所以来这里修炼的弟子都是修为极高的。无欲，也是慈航静斋的弟子追
求的终极目标之一。
LONG);

  set("exits", ([ 

  "west":__DIR__"qusutang",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  
  set("valid_startroom", 1);
  setup();
 
}

