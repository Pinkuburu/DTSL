
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是净念禅院的小路。北面是个菜园。东面是禅院的练武场了，
从那里不时传来了阵阵吆喝的声音。阵阵梵呗诵经之声，悠悠扬扬的似
从遥不可知的远处传来，传遍寺院。
LONG);

  set("exits", ([ 
	  "north":__DIR__"caiyuan",
	  "east":__DIR__"wuchang",
	  "southwest":__DIR__"xiaolu6",
      ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

