
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里是片草地。地上细草柔软，走起来十分舒服。北面是个练武场，
不时从那里传来呼喝的声音。有几个独尊堡弟子从你的身旁匆匆走过。
LONG);

  set("exits", ([ 
	  "north":__DIR__"wuchang",
	  "south":__DIR__"xilang2",
	  "west":"/d/clone/room/orgsaferoom/duzun/duzuntang",
        ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
