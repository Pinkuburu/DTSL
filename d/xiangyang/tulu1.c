
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里是条土路。不时有几骑快马飞快跑过。这里是湖北和四川的交
界处。
LONG);

  set("exits", ([ 
 "east":__DIR__"xiguanlu2",
 "southwest":__DIR__"tulu2",
        ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

