
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","春风楼");
  set ("long", @LONG
这里是扬州城的最大的青楼--春风楼。这里的姑娘都是扬州标致的
女子。到扬州来的江湖豪客，如果不来春风楼，就算没有真正的逛过扬
州城。如今世道混乱，这里也是一个让人逃避现实麻醉自己的好地方。
LONG);

  set("exits", ([ 
 "west":__DIR__"nandajie1",
       ]));
  set("objects",([
	  __DIR__"npc/girl":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

