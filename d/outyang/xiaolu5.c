
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路，北面就快到彭城了。这里的行人渐渐的多了起来
不时的能看到一些身背兵器的武林人士从你的身旁驰过。
LONG);

  set("exits", ([ 
 "southwest":__DIR__"xiaolu2",
 "northeast": "/d/yangzhoubei/shanlu13",
 
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

