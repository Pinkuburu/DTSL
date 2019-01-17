
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","练武场");
  set ("long", @LONG
这里是阴癸派的练武场。阴癸派的弟子平时都在这里练习武功。只
听呼喝的声音不时传来。还有几个弟子在远处修习着阴癸派的内功，脸
上红光闪现，透漏出一股诡异的气氛。练武场的弟子武功的招数也是个
个阴毒，凶险无比。
LONG);
  set("exits",([
	  "east":__DIR__"qingshilu3",
	  "north":__DIR__"bingqifang",
	  "south":__DIR__"woshi3",
	  ]));
  set("objects",([
	  __DIR__"npc/dizi1":2,
	  __DIR__"npc/yun":1,
	  ]));
  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

