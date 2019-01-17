
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里是一片草地。平时很少有人到这里来。东面是禅院弟子休息的
地方，不时传来睡觉打鼾的声音。阵阵梵呗诵经之声，悠悠扬扬的似从
遥不可知的远处传来，传遍寺院。
LONG);

  set("exits", ([ 
	  "northwest":__DIR__"caodi2",
	  "east":__DIR__"woshi",

         ]));

  set("outdoors","chanyuan");
  set("valid_startroom", 1);
  setup();
 
}

