
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里是条土路。从这里往北走，就可以到九江，往西南走，可以到
巴陵和岭南。
LONG);

  set("exits", ([ 
 "north":__DIR__"tulu1",
 "southwest":__DIR__"shanlu1",
 "southeast":"/d/dongming/shanlu4",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

