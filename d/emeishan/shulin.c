
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是一片树林，每棵树木都有十来丈高，周围阡陌交错，几十丈
高的大树簇在一块，密实的枝叶象一蓬蓬巨伞般伸向天空，把阳光遮得
丝毫也无。你似乎迷失了方向，象没头苍蝇般到处乱闯。北面有一座小
屋。西边是一个悬崖。
LONG);

  set("exits", ([ 
 "north":__DIR__"wu",
 "west":__DIR__"xuanya",
 "south":__DIR__"shanlu2",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

