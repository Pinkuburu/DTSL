
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"饭堂"NOR);
  set ("long", @LONG
这里是老君观的饭堂。地上散乱地放着一些锅、碗等东西，桌子上
放着几碗米饭，看来已经很久没有人来过了。
LONG);

  set("exits", ([ 

 "west":__DIR__"tingyuan",
         ]));
  set("objects",([
	  __DIR__"obj/rice":3,
	  ]));

  set("valid_startroom", 1);
  setup();
 
}

