
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","扁舟");
  set ("long", @LONG
这是一个行驶于淮河两岸的小舟。河水平静，梢公在船尾轻松自如
地摆着舵。
LONG);

set("outdoors","yangzhou");
  set("valid_startroom", 1);
  setup();
 
}

