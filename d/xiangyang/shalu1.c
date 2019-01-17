
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","沙石路");
  set ("long", @LONG
这里是一条沙石路。这里的天气有些炎热。头顶有一些不知名的小
鸟在跳来跳去，四周丛林密布，鲜花绿草若隐若现。
LONG);

  set("exits", ([ 

  "north":__DIR__"tulu6",
  "southeast":__DIR__"shalu2",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

