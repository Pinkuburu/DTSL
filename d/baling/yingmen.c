
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","军营大门");
  set ("long", @LONG
这里是梁朝的驻军大营。这里几乎没有行人进进出出的多是官兵，
不时也有武林人物进出，门口有两个士兵在站岗，好象一般的人是
不让进出的。
LONG);

  set("exits", ([ 

  "southeast":__DIR__"guandao3",
  "north":__DIR__"yingdi",
       ]));
set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

