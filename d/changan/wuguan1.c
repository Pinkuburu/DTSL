
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","武馆大院");
  set ("long", @LONG
这是个大院子，东西两边都是练武场，不少人在这里习武强身，这
里很吵，乱烘烘的，你看见不时有扛着东西的，挑着水的匆匆而过，北
面上了台阶就是武馆大厅。
LONG);

  set("exits", ([ 
 "west":__DIR__"wuguan",
 "northup":__DIR__"wuguan2",
        ]));
  set("objects",([
	  __DIR__"npc/dizi":1,
	  ]));
set("valid_startroom", 1);
  setup();
 
}

