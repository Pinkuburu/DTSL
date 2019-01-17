
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","游龙峰");
  set ("long", @LONG
这里就是卧龙岭上的游龙峰，这里地势狭长，两旁是陡峭的悬崖。
向西北望去，可以远远望到卧龙岭的浮云坪，在阳光的照耀下，积雪反
射的光芒把浮云坪装饰的好似一面大镜子。西边是卧龙岭的望天角。
LONG);

  set("exits", ([ 
 "westdown":__DIR__"wolong2",
 "eastup":__DIR__"wolong6",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

