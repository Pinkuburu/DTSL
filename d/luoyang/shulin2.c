
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是一个树林。这里树木茂盛，使树林看起来有些阴暗。你不禁
加快了脚步。
LONG);

  set("exits", ([ 
  "northeast":__DIR__"shulin1",
  "southwest":__DIR__"shashilu1",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

