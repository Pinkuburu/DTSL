
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","石牌坊");
  set ("long", @LONG
这里是一个石牌坊。上书“忠信礼义”四个大字。独尊堡虽然势力
独霸一方，但却从来不做任何奸邪之事，所以这四个字被独尊堡弟子牢
记心中。有几个独尊堡弟子不时从你的身旁匆匆而过。
LONG);

  set("exits", ([ 
  
	  "south":__DIR__"shilu",
	  "north":__DIR__"zhaobi",
         ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
