
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","广场");
  set ("long", @LONG
这里是襄阳的中心了。虽然是一城的中心，但却丝毫没有热闹的景
象，显得有些冷清。只见一个小商贩从你的身旁慢慢走过，他的小车上
装了很多货物，但却一件都没有卖出去。远处可以看见几个军官正骑着
飞马弛来，更是将道路两边的摊子撞得七凌八落。
LONG);

  set("exits", ([ 
 "east":__DIR__"dongdajie1",
 "west":__DIR__"xidajie3",
 "north":__DIR__"beidajie1",
 "south":__DIR__"nandajie1",
        ]));
       set("objects",([
      "/u/kouzhong/walker":1,
     ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

