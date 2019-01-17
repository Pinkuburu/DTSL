
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西市西口");
  set ("long", @LONG
这里就是位于和光大街上的闻名长安的西市－利人市的西口，十字
路口向东，就能走到热闹非凡的西市。西面是一片寂静的民居。
LONG);

  set("exits", ([ 
 "north":__DIR__"xishixikou1",
 "south":__DIR__"hgdajie1",
 "west":__DIR__"changanfang",
 "east":__DIR__"xishixijie4",
        ]));
  
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

