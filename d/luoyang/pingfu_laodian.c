
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","平福老店");
  set ("long", @LONG
这里是一间香料铺，在洛阳极为出名。许多小姐都来这里买香料，
用以熏睡帐和被褥。这里还有价格极高的极品丹桂花提炼制成的香料，
这是只有有钱人家才买得起的。
LONG);

  set("exits", ([ 
  "west":__DIR__"nanjie4",
         ]));
  set("objects",([
	  __DIR__"npc/xiangliao_laoban":1,
	  ]));
  set("valid_startroom", 1);
  set("resource/water",1);
  setup();
 
}

