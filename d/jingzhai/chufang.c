
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"厨房"NOR);
  set ("long", @LONG
这里是慈航静斋的厨房。这里非常清净，面前是一个大方桌，上面
放着几个馒头，还有几碗清水。你不禁有些饿了。
LONG);

  set("exits", ([ 

  "west":__DIR__"suishilu2",
     ]));
 set("no_fight",1);
  set("objects",([
	  __DIR__"obj/mantou":3,
	  __DIR__"npc/chuzi":1,
	  ]));
  set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}

