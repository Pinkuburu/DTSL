
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北天街");
  set ("long", @long
这里是洛阳的北天街，南去是洛阳客栈，北往则是洛阳最著名的曼
青院。
long);

  set("exits", ([ 
  
      "south":__DIR__"beijie1",
      "north":__DIR__"beijie3",
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

