
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","洛阳天坊");
  set ("long", @LONG
这里是洛阳天坊。这里临街的都是一处处官宅和商馆，主要提供给
各地来往洛阳的官员和商人居住。
LONG);

  set("exits", ([ 
      "east":__DIR__"shangguan2",
      "west":__DIR__"guanzhai2",
      "north":__DIR__"qinglongjie",
      "south":__DIR__"qinglongjie2",
  ]));

  set("outdoors","luoyang");

  set("valid_startroom", 1);

  setup();
}

