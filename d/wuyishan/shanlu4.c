
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。这里可以听到轰鸣的声音，看来附近有一个瀑布。
这里几乎没有什么人来，你不禁小心起来。
LONG);

  set("exits", ([ 

   "northwest":__DIR__"shanlu3",
    "east":__DIR__"pubu",
           ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

