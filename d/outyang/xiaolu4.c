
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路。这里是安徽和江苏的交界处。由于扬州是繁华之
地，所以这里的行人渐渐多了起来。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"xiaolu3",
 "southeast":__DIR__"dalu1",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

