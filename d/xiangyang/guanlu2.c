
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是襄阳城的东门外的官路。这里人来人往非常繁忙，不时有人
骑着马匆匆而过。西面就是襄阳城了。
LONG);

  set("exits", ([ 
"west":__DIR__"guanlu1",
"north":__DIR__"caodi2",
"northeast":"/d/hefei/dalu2",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

