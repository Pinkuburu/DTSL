
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","沙石路");
  set ("long", @LONG
这里是一条沙石路。大风吹来，卷起阵阵风沙。不时有武林人士骑
马而过。
LONG);

  set("exits", ([ 
  "northeast":__DIR__"shulin2",
  "southwest":__DIR__"shashilu2",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

