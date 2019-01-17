
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","王府大门");
  set ("long", @LONG
这里就是李世民在长安的王府，里面屋宇楼阁，气势非凡。由于这
里是王府所在，是李世民等王府要员在这里办公之地，所以守卫深严，
平常百姓更是不得接近。
LONG);

  set("exits", ([ 
 "north":__DIR__"changlang1",
 "south":__DIR__"jinshuiqiao",
        ]));
  set("objects",([
	 "/d/changan/npc/bing":2,
	  ]));

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

