
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西市南口");
  set ("long", @LONG
这里就是位于兴平大街上的闻名长安的西市－利人市的南口，丁字
路口向北，就能走到热闹非凡的西市。
LONG);

  set("exits", ([ 
 "north":__DIR__"xishidongjie5",
 "eastup":__DIR__"xpqiao",
 "west":__DIR__"xishinankou1",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

