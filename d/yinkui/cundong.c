
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","村东");
  set ("long", @LONG
这里是村子的东面。这个村子据说已经很久没有人住了。里面死气
沉沉的，很少有人去那里。
LONG);

  set("exits",([
	  "east":__DIR__"xiaolu1",
	  "west":__DIR__"cunzhong",
	  ]));
  set("outdoors","yinkui");
  set("valid_startroom", 1);
  setup();
 
}

