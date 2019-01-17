
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路。南边就是长江了。渐渐显得有些热闹了。不时有
大队的官兵从你的身旁走过，吓得路上的百姓都朝两边闪去。这里风景
秀丽，山水如画，空气清新。
LONG);

  set("exits", ([ 
 "north":__DIR__"guanlu4",
 "southeast":__DIR__"xiaolu2",
 "east":"/d/jiujiang/xiaojing2",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

