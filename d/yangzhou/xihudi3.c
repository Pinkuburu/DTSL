
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西湖堤");
  set ("long", @LONG
这里是扬州城的西湖堤。这里停靠着几艘已经修补好的花船，三三两
两的船工或坐或卧，随地休息着。
LONG);

  set("exits", ([
 "southwest":__DIR__"xihudi2",
 "north":__DIR__"xihudi4",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

