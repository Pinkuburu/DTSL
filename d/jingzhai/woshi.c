
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"卧室"NOR);
  set ("long", @LONG
这里是间卧室。慈航静斋的弟子都在这里这里休息。这里供着一尊
佛像。你来到这里，不禁有些困了。
LONG);

  set("exits", ([ 

  "north":__DIR__"xiuluoyuan",
  
    ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/

  set("sleep_room",1);
  set("valid_startroom", 1);
  setup();
 
}

