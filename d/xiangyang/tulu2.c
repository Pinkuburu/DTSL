
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里是条土路。这里是四川的境地。往东走就是湖北的境地了。不
时有几骑快马飞快跑过。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"tulu1",
 "west":"/d/dabashan/shanjiao",
 "north":__DIR__"nongtian",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

