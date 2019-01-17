
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北大街");
  set ("long", @LONG
这里是襄阳的北街。北面就是襄阳的北门了。这里的行人不是很多。
西边有一家茶馆，[茶香飘三里]的帆布招牌迎风招展，老远就可以清楚地
看到。
LONG);

  set("exits", ([ 
 "north":__DIR__"beimen",
 "south":__DIR__"beidajie2",
 "west":__DIR__"chaguan",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

