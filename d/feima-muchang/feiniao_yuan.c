
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"飞鸟园"NOR);
  set ("long", @LONG
园林美景层出不穷，远近房屋高低有序，错落于林木之间，雅俗得
体。最别致处是由于庄园居于高处，不时可看到飞马城下延展无尽的牧
场美景，在新月斜照下越见安详宁和。
LONG);

  set("exits", ([ 
	  "south":__DIR__"qingshilu5",
	  "north":__DIR__"woshi1",
	  "east":__DIR__"shufang",
	  "west":__DIR__"qingshilu6",
    ]));
  set("objects",([
	  __DIR__"npc/liuzong-dao":1,
	  ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
  "/obj/sboard/feima_b.c"->foo();

 
}

