
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是条山路。四下望去，路边有几具死尸，看来北方的生活同样
艰苦。不时可以听到哭泣的声音。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu8",
 "southwest":__DIR__"tulu",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

