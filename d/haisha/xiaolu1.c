
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是渔村的内的一条小路，四下望去，一片荒凉的景色。偶尔能
听到一两声吆喝的声音，好象是有人在练习武艺。
LONG);

  set("exits", ([ 

  "west":__DIR__"cunxi",
  "east":__DIR__"xiaolu2",
  "north":__DIR__"caodi1",
  "south":__DIR__"caodi2",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

