
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西湖堤");
  set ("long", @LONG
这里是扬州城的西湖堤。西边传来一些喧哗声，这里主要是修补各
种花船的地方，可以说整个扬州都和烟花柳巷脱不开干系。
LONG);

  set("exits", ([ 
 "southeast":__DIR__"nanhudi",
 "north":__DIR__"xihudi2",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

