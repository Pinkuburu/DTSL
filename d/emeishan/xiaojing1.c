
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小径");
  set ("long", @LONG
这里是一条上山的小径。周围是峨眉山秀丽的风光。不时有游人和
你擦肩而过。
LONG);

  set("exits", ([ 
 "eastup":__DIR__"xiaojing2",
 "southdown":__DIR__"shanjiao",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

