
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","长升大街");
  set ("long", @LONG
这是长升大街，南北连接长安城的长乐坊和升道坊。这里不再那么
静悄悄了，街上十分热闹，人来人往川流不息。西面就是长安有名的东
市了。
LONG);

  set("exits", ([ 
 "north":__DIR__"dongshidongkou2",
 "south":__DIR__"xpdajie7",
 "east":__DIR__"xunbufang",
       ]));
  set("objects",([
 "/d/job/tujuejob/shijie":1,
	  ]));
	  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

