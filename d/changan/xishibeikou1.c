#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西市北口");
  set ("long", @LONG
这里就是位于光明大街上的闻名长安的西市－利人市的北口，丁字
路口向南，就能走到热闹非凡的西市。
LONG);

  set("exits", ([ 
 "south":__DIR__"xishixijie1",
 "west":__DIR__"gmdajie7",
 "east":__DIR__"xishibeikou2",
        ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

