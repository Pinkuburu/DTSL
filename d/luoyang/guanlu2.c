
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是洛阳南门的官路。这里已经到了郊区了。不时有武林人士走
过。南边就是秦岭了。
LONG);

  set("exits", ([ 
  "northeast":__DIR__"guanlu1",
  "southwest":__DIR__"shanlu1",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

