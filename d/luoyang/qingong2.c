
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIY"寝宫"NOR);
  set ("long", @LONG
这里就是洛阳皇宫的寝宫了。这里摆设豪华，两边的墙上挂着名贵
的字画，地上是猩红地毯，里面放着皇后的宽大的床。这里打扫的一尘
不染，平时有宫女在这里。
LONG);

  set("exits", ([ 
  
  
  "south":__DIR__"liangtai",

         ]));

  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

