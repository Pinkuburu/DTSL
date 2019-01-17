
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里是一片草地，一片翠绿映入眼帘，让人觉得非常舒服，一身的
疲劳似乎一扫而光。北边是一个卧室，是大江联弟子们休息、睡觉的地
方。
LONG);

  set("exits", ([ 
 "southup":__DIR__"suishilu",
 "northeast":__DIR__"woshi",
 "west":__DIR__"lingwuroom",
      ]));
  set("valid_startroom", 1);
  set("outdoors","dajianglian");
  setup();
 
}
