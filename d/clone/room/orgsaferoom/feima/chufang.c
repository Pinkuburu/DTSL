
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","厨房");
  set ("long", @LONG
这里是飞马牧场的厨房。这里香气四溢，一进来就让人不住地流出
口水。有几个厨子正在那里忙着做饭，旁边有几个飞马牧场弟子正在狼
吞虎咽地吃着饭。
LONG);

  set("exits", ([ 
 "northup":__DIR__"huayuan",
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
