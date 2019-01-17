
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","襄王大街");
  set ("long", @LONG
这里是洛阳的襄王大街。再往东走，就到了洛阳的东门。虽是战乱
，但依然不减洛阳的繁华，还有很多人从东门涌入，官兵正严密地检查
着来往的行人。只听马车声，呼喝声，吵叫声不绝于耳。
LONG);

  set("exits", ([ 
  
  "west":__DIR__"xiangwangjie2",
  "east":__DIR__"dongmen",
  "northeast":__DIR__"dongbianmen1",
  "north":__DIR__"qingshilu2",
  "south":__DIR__"matou",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}
