
inherit ROOM;
#include <job_money.h>
void create ()
{
  set ("short","港口");
  set ("long", @LONG
这里九江的西港口。东边是九江的主港口。这里非常热闹，各种船
只停泊在这里，商船、鱼船，挤得水泻不通。旁边还有很多小贩，叫卖
声音不绝于耳。
LONG);

  set("exits", ([ 
      "east":"/d/jiujiang/matou",
      ]));
  set("valid_startroom", 1);
  set("outdoors","jiujiang"); 
  setup();
 
}

