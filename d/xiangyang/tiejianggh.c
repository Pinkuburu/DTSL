#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","铁匠工会");
  set ("long", @LONG
这里铁匠们的工会，关于铁匠的大小事情都在这里处理，里面放着
各种各类的打铁用具，一个铁匠正在指导其他的学徒使用这些东西，东
面有一条通往工场的走廊。
LONG);

  set("exits", ([ 
 "out":__DIR__"bingqipu",
 "east":__DIR__"gongchang",
       ]));
  set("objects",([
	  "/d/job/tiejiangjob/tiejiang1":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

