
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是一片一望无垠林海，每棵树木都有十来丈高，周围阡陌交错，
几十丈高的大树簇在一块，密实的枝叶象一蓬蓬巨伞般伸向天空，把阳光
遮得丝毫也无。你似乎迷失了方向，象没头苍蝇般到处乱闯。这里快出了
湖南的境地了。
LONG);

  set("exits", ([ 

  "north":__DIR__"shalu3",
  "southeast":__DIR__"tree2",
 "northwest":"/d/quest/jinlongzhang/suishilu1",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

