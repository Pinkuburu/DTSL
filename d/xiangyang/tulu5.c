
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里已经是湖南的境地了。这是一条土路。来来往往不少人，不时
有几骑快马飞快跑过，尘土飞扬。
LONG);

  set("exits", ([ 

  "southwest":__DIR__"tulu6",
  "north":__DIR__"jiangnan",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

