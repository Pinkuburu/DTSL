
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","静心庵");
  set ("long", @LONG
静心庵位于宝掌峰下，庵前有大峨石和玉液泉，泉出石下，清澈无
比，终年不涸。一株大海棠树，已是数百苍龄，抱可数围，高达十余丈。
LONG);

  set("exits", ([ 
 "northdown":__DIR__"shiqiao",
 "westup":__DIR__"gelou",
 "southup":__DIR__"shanlu6",
      ]));
 set("valid_startroom", 1);
  setup();
 
}

