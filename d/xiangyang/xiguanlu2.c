
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是条官路。东面是襄阳的西门。往西走就要到四川的境地了。
这里的行人不是很多。
LONG);

  set("exits", ([ 
 "east":__DIR__"xiguanlu1",
 "west":__DIR__"tulu1",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

