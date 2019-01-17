
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是条小路。整条路由细碎的小石子铺成。西边是宋家堡的厨房，
从那里传来阵阵饭香。不时有宋家堡的弟子从那里进进出出。
LONG);

  set("exits", ([ 

  "northeast":__DIR__"xiaoqiao2",
  "west":__DIR__"chufang",
      ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

