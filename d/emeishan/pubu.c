
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","瀑布");
  set ("long", @LONG
这里是一个瀑布。瀑布不是很大，但是气势惊人，轰轰声音不绝于
耳。你不禁为这里的气氛所感染。
LONG);

  set("exits", ([ 
 "south":__DIR__"shilin",
       ]));
 set("objects",([ "/d/clone/npc/beast/laohu":1,]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

