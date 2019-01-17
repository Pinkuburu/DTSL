
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","董家酒楼");
  set ("long", @LONG
这里是洛阳著名的董家酒楼。这里生意特别好，每天人来人往，络
绎不绝。很多武林人士在这里谈论天下大事，或是谈论和氏璧。伙计跑
来跑去忙个不停。
LONG);

  set("exits", ([ 
  
      "north":__DIR__"luoshuidi3",
      "east":__DIR__"tianjie4",
         ]));
  set("objects",([
	  __DIR__"npc/dong":1,
__DIR__"npc/xiaoer4":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

