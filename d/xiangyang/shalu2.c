
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","沙石路");
  set ("long", @LONG
这里是一条沙石路。据说这里经常有乱匪出现，你不禁小心起来。
头顶有一些不知名的小鸟在跳来跳去，四周丛林密布，鲜花绿草若隐若
现。
LONG);

  set("exits", ([ 

  "northwest":__DIR__"shalu1",
  "southeast":__DIR__"shalu3",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

