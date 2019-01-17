

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"青石路"NOR);
  set ("long", @LONG
这里是条青石路，通往皇宫的西门。门口经常停着几辆大车，那是
参见皇上的大臣们所乘坐的。平时这里戒备森严，官兵不允许普通百姓
在这里停留的。
LONG);

  set("exits", ([ 
  
  "northeast":__DIR__"westdoor",
  "south":__DIR__"xiangwangjie1",
         ]));

  
  set("valid_startroom", 1);
  setup();
 
}

