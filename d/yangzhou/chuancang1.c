
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","赌场");
  set ("long", @long
画舫不止可以观看舞蹈，还可以赌博，这里就是一处精致的赌场。
long);

  set("exits", ([ 
 "south":__DIR__"chuancang",
 "north":__DIR__"chuancang2",
 
        ]));
 set("objects",([
	 __DIR__"npc/yahuan1":2,
	 ]));
  set("valid_startroom", 1);
  setup();
 
}

