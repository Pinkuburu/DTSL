
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小径");
  set ("long", @LONG
这里是一条上山的小径。你不禁为娥眉山的景色所吸引。从这里可
以看到山下的风光。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"caodi1",
 "westdown":__DIR__"xiaojing1",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

