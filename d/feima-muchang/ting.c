
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"六角小亭"NOR);
  set ("long", @LONG
这里是个六角小亭，从这里可以整个后园的景色。整个后园的景色
别致，布置隐含机关之学，看起来似乎是一个武林高人所做。后园是飞
马牧场的禁地，平时没有人去那里。
LONG);

  set("exits", ([ 
	  "southwest":__DIR__"hehuachi",
   ]));

  
  set("valid_startroom", 1);
  setup();
 
}

