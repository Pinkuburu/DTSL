
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","码头");
  set ("long", @LONG
这里是巴陵的码头。靠在岸边的船密密麻麻，有鱼家用的小鱼船、
运货用的商船、还有普通人用不起的官船，船上船下人们忙落异常。旁
边好象有搭客的商船。
LONG);

  set("exits", ([ 

  "south":__DIR__"guandao4",
       ]));

set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

