
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","小径");
  set ("long", @LONG
这里是条小径。地上铺着细碎的小石。这里清幽典雅，你不由小心
起来。东边是一间客房。
LONG);

  set("exits", ([ 

  "north":__DIR__"houbao",
 "southeast":__DIR__"xiaojing2",
 "east":__DIR__"kefang",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

