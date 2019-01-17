
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南门");
  set ("long", @LONG
这里是扬州城的南门。由于扬州自古就是繁华的城市，所以来往的
游人很多。这里有几个官兵，在检查来往的行人。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"nandajie3",
 "south":"/d/hangzhou/jiangbei",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

