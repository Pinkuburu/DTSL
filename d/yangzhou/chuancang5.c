
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","杂货间");
  set ("long", @long
这里是画舫存放杂货的地方。再往后去就是后甲板了。
long);

  set("exits", ([ 
 "north":__DIR__"chuancang6",
 "down":__DIR__"dicang",
 "south":__DIR__"chuancang2",
 ]));
 
  set("valid_startroom", 1);
  setup();
 
}

