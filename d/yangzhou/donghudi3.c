
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东湖堤");
  set ("long", @LONG
这里是扬州城的东湖堤。东边传来一些喧哗声，打破了这里的宁静。
LONG);

  set("exits", ([ 
 "north":__DIR__"donghudi2",
 "south":__DIR__"donghudi4",
 "southeast":__DIR__"dongdajie1",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

