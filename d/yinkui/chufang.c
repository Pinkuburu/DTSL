
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","厨房");
  set ("long", @LONG
这里是阴癸派的厨房。有几个厨子正在那里忙碌着，一会就有新做
好的菜放到了桌子上。桌子上放了很多精美的菜肴，有几个弟子正在那
里狼吞虎咽，你不禁有些饿了。
LONG);
  set("exits",([
	  "west":__DIR__"xiaolu",
	  ]));
  set("objects",([
	  __DIR__"obj/food1":2,
	  __DIR__"obj/food2":2,
	  __DIR__"obj/food3":2,
	  "/d/clone/npc/chuzi":1,
	  ]));

  set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}

