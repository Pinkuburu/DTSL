
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是一片树林。这里已经是河南境地。不知道这里有没有强盗。
你加快了前进的脚步。
LONG);

  set("exits", ([ 
 "east":"/d/xingyang/dadao4",
 "west":__DIR__"shulin6",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

