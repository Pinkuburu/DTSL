
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里是条土路。南面是洛阳城的北门。这里的行人很多，有很多武
林人士走过。
LONG);

  set("exits", ([ 

  "south":__DIR__"beimen",
 "northeast":__DIR__"tulu2",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

