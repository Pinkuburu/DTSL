
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","大路");
  set ("long", @LONG
这里是一条宽敞的大路。南边不远就是合肥了。这里的行人渐渐多
了起来。不时有人骑马从你的身旁驰过。
LONG);

  set("exits", ([ 
 "northeast": "/d/outyang/xiaolu2",
 "southwest":__DIR__"dalu2",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

