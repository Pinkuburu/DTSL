
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIR"执法堂"NOR);
  set ("long", @LONG
这里是海沙帮的执法堂，这里摆放了各种刑具。有几名海杀弟子正
在那里受刑，呻吟连天。
LONG);

  set("exits", ([ 

  "southwest":__DIR__"xiaolu3",
       ]));
       /*
  set("objects",([
  "/d/job/banghuijob/haisha":1,
  ]));
  */
  set("valid_startroom", 1);
  setup();
 
}

