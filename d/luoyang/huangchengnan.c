
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","皇城南门");
  set ("long", @LONG
这里是皇城的南门。往北走可以到永冬门。可以看到有几个官兵正
在严密地检查来往的行人。
LONG);

  set("exits", ([ 
  
  "north":__DIR__"yongdongjie2",
  "south":__DIR__"jiashan",
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

