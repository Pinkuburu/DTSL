
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。这里分路很多，走不好，就非常容易迷路了。你
仔细打量了这里一下。不时有人从你的身旁走过。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shanlu4",
 "south":__DIR__"shanlu2",
 "southwest":__DIR__"shanlu11",
 "west":__DIR__"shalu1",
        ]));
  set("objects",([
     __DIR__"npc/shangren":1,
     ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

