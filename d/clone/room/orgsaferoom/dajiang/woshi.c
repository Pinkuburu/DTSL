
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","卧室");
  set ("long", @LONG
这里是间卧室。这里摆放着几张大床，床的被褥整齐。这里是大江
联弟子休息的地方。旁边的墙上挂着一口宝剑和一幅字画，一看就是出
自名家手笔。
LONG);

  set("exits", ([ 
 "southwest":__DIR__"caodi",
      ]));
  set("valid_startroom", 1);
  set("sleep_room",1);
  setup();
 
}
