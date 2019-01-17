
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","大路");
  set ("long", @LONG
这里是一个宽敞的大路。道路宽敞，路上的行人很多。不时有人骑
着马从你的身旁匆匆驰过。南边就是岭南宋家堡了。
LONG);

  set("exits", ([ 

  "north":__DIR__"dalu1",
  "south":__DIR__"door",
  "northeast":"/d/jiujiang/shanlu4",
         ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

