
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","厨房");
  set ("long", @LONG
这里是天策府的厨房。这里香气四溢，一进来就让人不住地流出口
水。有几个厨子正在那里忙着做饭，旁边有几个天策府弟子正在狼吞虎
咽地吃着饭。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"changlang1",
      ]));
  set("resource/water",1);
  set("objects",([
    "/d/clone/room/orgsaferoom/obj/baozi":2,
    "/d/clone/room/orgsaferoom/obj/xiangsuji":2,
    "/d/clone/room/orgsaferoom/obj/kaoya":2,
    "/d/clone/room/orgsaferoom/obj/yangtui":2,
  ]));
  set("valid_startroom", 1);
  setup();
 
}
