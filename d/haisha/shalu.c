
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","沙路");
  set ("long", @LONG
这里是一片细沙路。这里的人不是很多。向南边望去，隐隐约约是
一个帐棚，但里面却没有丝毫的声音。
LONG);

  set("exits", ([ 
 "north":__DIR__"caodi2",
  "southeast":__DIR__"juyipeng",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

