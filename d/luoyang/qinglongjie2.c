
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","洛阳地坊");
  set ("long", @LONG
这里是洛阳地坊。这里临街的都是一处处官宅和商馆，主要提供给
各地来往洛阳的官员和商人居住。
LONG);

  set("exits", ([ 
      "east":__DIR__"shangguan1",
      "west":__DIR__"guanzhai1",  
      "north":__DIR__"qinglongjie3",
  "south":__DIR__"qinglongjie1",
         ]));
  set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

