
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","延嘉殿");
  set ("long", @LONG
延嘉殿内金砖铺地，坐北向南设雕镂金漆宝座。东西两梢间为暖阁，
安板门两扇，上加木质浮雕如意云龙浑金毗庐帽。建筑上采用了减柱造
做法，将殿内前檐金柱减去六根，使空间宽敞。 
LONG);

  set("exits", ([ 
 "northdown":__DIR__"yuhuayuan",
 "south":__DIR__"ganludian",
        ]));
  /*set("objects",([
	  "/d/changan/npc/liyuanba":1,
	  ]));
  */
  set("valid_startroom", 1);
  setup();
 
}

