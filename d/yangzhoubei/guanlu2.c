
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是扬州城北的官路。向北边望去，可以望到扬州的城们了。不
时有游人从你的身旁走过。看来扬州的繁华依旧不减从前。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"xiaolu1",
 "south":__DIR__"guanlu1",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

