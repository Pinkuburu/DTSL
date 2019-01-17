
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路，北面就是淮河的南岸了。这里的行人不是很多。
不时有人骑着马从你的身旁驰过。
LONG);

  set("exits", ([ 
 "north":__DIR__"huaihenan",
 "southeast":__DIR__"xiaolu3",
 "northeast":__DIR__"xiaolu5",
 "southwest": "/d/yangzhoubei/dalu1",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

