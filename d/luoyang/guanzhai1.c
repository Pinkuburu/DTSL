
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官宅");
  set ("long", @LONG
这里是供外地到洛阳办事的官员所居住的地方。虽然有些简朴，但
是不失尊贵
LONG);

  set("exits", ([ 
      "east":__DIR__"qinglongjie2",
  ]));
  set("valid_startroom", 1);
  setup();
 
}

