
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","休息室");
  set ("long", @LONG
这里是独尊堡的弟子平时休息的地方。床上的被褥有些凌乱了，有
几个弟子正在床上睡着觉，发出轻微的鼾声。你来到这里，不禁有些困
了。
LONG);

  set("exits", ([ 
	  "south":__DIR__"wuchang",
        ]));
  set("sleep_room",1);
set("valid_startroom", 1);
  setup();
 
}
