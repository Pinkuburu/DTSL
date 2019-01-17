
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","浮云坪");
  set ("long", @LONG
这里就是卧龙岭上的浮云坪。这里地势宽阔，是一片平地。白雪覆
盖其上，好似一面镜子一般。北边是高耸的峭壁。向上望去，隐约可以
看见几座房屋闪现其中。南边是望天角，是卧龙岭较为险要的地方。
LONG);

  set("exits", ([ 
 "southdown":__DIR__"wolong2",
 "east":__DIR__"wolong4",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

