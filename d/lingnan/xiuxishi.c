
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","休息室");
  set ("long", @LONG
这里是宋家堡弟子练习武艺后休息的地方。床上的被褥有些凌乱，
有几个宋家堡的弟子正在上面熟睡，发出轻微的鼾声。你来到这里，
不觉得有些困了。
LONG);

  set("exits", ([ 

   "north":__DIR__"wuchang",
     ]));
  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

