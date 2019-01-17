
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北门");
  set ("long", @LONG
这里是扬州城的北门。扬州自古以来就是繁华热闹的地方，所以来
往的游人很多。这里有几个官兵，在检查来往的行人。
LONG);

  set("exits", ([ 
 "southwest":__DIR__"beidajie2",
 "north":"/d/outyang/guanlu4",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

