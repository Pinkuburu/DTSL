
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIY"寝宫"NOR);
  set ("long", @LONG
这里就是洛阳皇宫的寝宫了。这里摆设豪华，两边的墙上挂着名贵
的字画，地上是猩红地毯，里面放着皇上的宽大的床。里面的桌子上堆
了很多大臣的奏折，但是看起来很久没动过了，已经落了一层灰尘。
LONG);

  set("exits", ([ 
  "south":__DIR__"yuhuayuan",

         ]));
  set("objects",([
	  __DIR__"npc/yangguang":1,
	  ]));
  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

