
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是渔村的内的一条小路，四下望去，一片荒凉的景色。北边不
时传来一两声吆喝的声音，好象是有人在练习武艺。
LONG);

  set("exits", ([ 

  "west":__DIR__"xiaolu1",
  "east":__DIR__"xiaolu3",
  "northeast":__DIR__"wuchang",
  "south":__DIR__"xiaolu4",
       ]));
  set("objects",([
	  __DIR__"npc/yangzhen":1,
	  ]));
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

