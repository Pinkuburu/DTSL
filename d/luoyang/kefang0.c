
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"客房"NOR);
  set ("long", @LONG
一般的妓院在客房的陈设上都以红色为主，这里的布置却别出心裁
采用绿色，到是给人一种清爽的感觉。
LONG);

  set("exits", ([ 
	  "down":__DIR__"xilou",
  ]));
  set("objects",([
  ]));

  set("valid_startroom", 1);
  setup();
 
}
