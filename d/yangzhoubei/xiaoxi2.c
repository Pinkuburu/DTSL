
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小溪");
  set ("long", @LONG
这里是一条小溪。清澈的溪水汩汩流下。北边是一条土路，不知道
通向何处。溪边绿草如茵，野花飘香，还飞舞着漂亮的蝴蝶。
LONG);

  set("exits", ([ 
 "northeast":"/d/xingyang/tulu2",
 "west":__DIR__"xiaolu3",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

