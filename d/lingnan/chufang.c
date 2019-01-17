
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","厨房");
  set ("long", @LONG
这里是宋家堡的厨房。几个厨师正在那里满头大汉地忙着，不是有
新的饭菜摆到了桌子上。有几个宋家堡的弟子正在那里狼吞虎咽地吃饭。
你来到这里，不觉流下了口水。
LONG);

  set("exits", ([ 

  "east":__DIR__"xiaolu",
    ]));
  set("objects",([
	  __DIR__"obj/niurou":3,
	  __DIR__"obj/kaoya":3,
	  "/d/clone/npc/chuzi":1,
	  ]));
set("resource/water",1);
  set("valid_startroom", 1);
 setup();
 
}

