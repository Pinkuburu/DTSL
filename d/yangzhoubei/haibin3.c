
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","海滨");
  set ("long", @LONG
这里是海滨。南边是茫茫的大海。这里已经北方地区了，天气有些
冷了，但是这里依旧海浪滚滚。
LONG);

  set("exits", ([ 
 "east":__DIR__"haibin4",
 "west":__DIR__"haibin2",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

