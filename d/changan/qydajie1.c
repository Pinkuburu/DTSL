
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","启予大街");
  set ("long", @LONG
这是启予大街，南北连接长安城的启夏门和丹凤门。街上十分热闹，
人来人往川流不息。东面是一所宅院。
LONG);

  set("exits", ([ 
 "north":__DIR__"qydajie2",
 "south":__DIR__"xpdajie5",
 "east":__DIR__"jingzhaolian",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

