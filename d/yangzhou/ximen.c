
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"西门"NOR);
  set ("long", @LONG
这里是扬州城的西门。这里的行人渐渐多了起来。扬州自古就是交
通枢纽，又是烟花胜地，自然来的人很多了。这里有几个官兵，检查着
来往的行人。
LONG);

  set("exits", ([ 
 "east":__DIR__"xidajie1",
 "west":__DIR__"guanlu1",
 "northwest":"/d/jiujiang/dalu4",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

