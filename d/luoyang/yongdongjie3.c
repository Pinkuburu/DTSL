
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","永冬大街");
  set ("long", @LONG
这里是洛阳的永冬大街。往北走可以到永冬门。可以看到有几个官
兵正在严密地检查来往的行人。
LONG);

  set("exits", ([ 
  
  "northwest":__DIR__"beimen2",
  "south":__DIR__"yongdongjie2",
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

