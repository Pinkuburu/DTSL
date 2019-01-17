
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","襄王大街");
  set ("long", @LONG
这里是洛阳的襄王大街。这里的人不是很多。只有几个武林人士出
没在这里。北边是洛阳的皇宫，很多官兵把守在那里，用凌厉的眼神打
量着过往的行人。
LONG);

  set("exits", ([ 
  
  "west":__DIR__"xiangwangjie1",
  "east":__DIR__"xiangwangjie3",
  "north":__DIR__"door",
  "south":__DIR__"kaiheqiao1"
 
         ]));
  set("objects",([
	  __DIR__"npc/gongzi":1,
	  ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

