
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东湖堤");
  set ("long", @LONG
这里是扬州城的东湖堤。这里的景色和北湖堤不同，幽静典雅，堤旁
杨柳依依，碧波荡漾，偶尔会有一些才子佳人在这里把臂同游，一副宁静
祥合的景象。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"donghudi",
 "south":__DIR__"donghudi3",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

