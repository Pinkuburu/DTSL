
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","扁鹊墓");
  set ("long", @LONG
扁鹊誉称神医，一生四海行医，后来到秦国，没想到这里竟是他的
最后归宿。据传，一代神医扁鹊冤死于暗杀，冤家却是他的同行，而此
处是他的埋骨之地。
LONG);

  set("exits", ([ 
"southwest":__DIR__"shanlu1",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

