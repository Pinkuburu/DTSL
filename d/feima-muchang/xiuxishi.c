
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","休息室");
  set ("long", @LONG
这里是飞马牧场的休息室。许多干活的人工人都在这里睡觉休息。
只听这里呼噜连天，炕上躺着很多人。你来到这里，不禁有些困倦了。
LONG);

  set("exits", ([ 
	  "south":__DIR__"caiyuan",
    ]));
  set("sleep_room",1);
  
  set("valid_startroom", 1);
  setup();
 
}

