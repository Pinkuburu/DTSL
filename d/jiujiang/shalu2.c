
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","沙路");
  set ("long", @LONG
这里是片沙路。这里离长江并不是很远。这里是安徽和浙江的交界
处了。往东走就是浙江，往西走就是安徽了。
LONG);

  set("exits", ([ 

  "east":__DIR__"shalu3",
  "southwest":__DIR__"shalu1",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

