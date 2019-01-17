
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是襄阳城的东门外的官路。这里人来人往非常繁忙，不时有人
骑着马匆匆而过。过往的行人都要受到严格的检查。
LONG);

  set("exits", ([ 
"west":__DIR__"dongmen",
"east":__DIR__"guanlu2",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

