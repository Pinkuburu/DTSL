
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是条官路。这里人来人往非常繁忙，不时有人骑着马匆匆而过。
东边就是合肥的西门了。这里的行人很多。
LONG);

  set("exits", ([ 

  "northeast":__DIR__"ximen",
  "southwest":__DIR__"wguanlu2",
       ]));
 
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

