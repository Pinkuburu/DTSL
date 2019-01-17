
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是扬州城的西门外的官路。西边就是扬州的西门了。现在的扬
州还是很繁华，所以这里的行人一点都不少。
LONG);

  set("exits", ([ 
 "east":__DIR__"ximen",
 "west":__DIR__"guanlu2",
        ]));
  set("objects",([
   __DIR__"npc/xingren":2,
   ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

