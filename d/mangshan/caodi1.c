
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里是片草地，阳光充足。你来到这里，不禁有些困了。这里风景
秀丽，山水如画，空气清新。不时有鸟儿从你的头上飞过。
LONG);

  set("exits", ([ 

  "north":__DIR__"shanlu6",
        ]));
  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

