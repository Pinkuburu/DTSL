
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是秦岭上的一条山路，这里不时地可以听到飞禽走兽的声音。
你不禁加快了脚步。
LONG);

  set("exits", ([ 
  "eastdown":__DIR__"shanlu2",
  "southdown":__DIR__"shanlu4",
  "north":__DIR__"songlin",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

