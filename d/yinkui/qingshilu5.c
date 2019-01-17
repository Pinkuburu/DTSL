
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","青石路");
  set ("long", @LONG
这里是一条青石路，路面是由上好的青砖铺成。西边是阴癸派的议
事广场。这里冷冷清清的，平时没有什么来这里。北边是阴癸派的炼丹
房，东北边有一个池塘。
LONG);
  set("exits",([
	  "west":__DIR__"qingshilu4",
	  "northeast":__DIR__"chitang",
	  "north":__DIR__"danfang",
	  ]));

  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

