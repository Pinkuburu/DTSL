
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","沙石路");
  set ("long", @LONG
这里是条沙石路。这里来来去去只有几个人。这里是河南和安徽的
交界处了。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shalu1",
 "southeast":__DIR__"shulin1",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

