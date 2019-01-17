
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里是一片草地。平时很少有人到这里来。前面是禅院弟子休息的
地方，不时传来睡觉打鼾的声音。阵阵梵呗诵经之声，悠悠扬扬的似从
遥不可知的远处传来，传遍寺院。
LONG);

  set("exits", ([ 
	  "westup":__DIR__"changlang3",
	  "southeast":__DIR__"caodi3",
	  "enter":__DIR__"anfang",

         ]));
    set("objects",([
	  __DIR__"npc/buju":1,
	  ]));
  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

