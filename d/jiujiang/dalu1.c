
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","大路");
  set ("long", @LONG
这里是个宽敞大路。这里的行人渐渐多了起来，有些热闹了。往东
边望去，可以隐隐约约看见扬州城了。
LONG);

  set("exits", ([ 

  "east":__DIR__"dalu2",
  "southwest":"/d/yangzhou/xiaolu1",
  
         ]));
  set("objects",([
	  __DIR__"npc/nvzi":1,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

