
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"白虎门"NOR);
  set ("long", @LONG
这里是洛阳的白虎门。从这里可以出洛阳城了。东面是洛阳的正南
门。
LONG);

  set("exits", ([ 
  

  "northwest":__DIR__"baihujie4",
  "east":__DIR__"nanmen",
  "south":__DIR__"guanlu1",

         ]));
  set("objects",([
	  __DIR__"npc/bing":1,
	  ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

