
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里是一条土路。耳中不时可以传来江水轰鸣的声音。北边是一个
凉亭。里面不时传来谈笑的声音。
LONG);

  set("exits", ([ 
	  "north":__DIR__"juyiting",
	  "east":__DIR__"tulu1",
	  "west":"/d/clone/room/orgsaferoom/dajiang/juyitang",
    ]));
set("outdoors","dajiang");
  /*set("objects",([
	  __DIR__"npc/dizi":2,
	  ]));*/
  set("valid_startroom", 1);
  setup();
 
}

