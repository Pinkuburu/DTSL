
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里是条土路。西边就是四川的东门了。这里的行人渐渐多了起来。
不时有几骑快马飞快跑过。
LONG);

  set("exits", ([ 
 "east":__DIR__"tulu3",
 "westup":"/d/chengdu/zhandao3",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

