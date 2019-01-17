
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西市西口");
  set ("long", @LONG
这里就是位于和光大街上的闻名长安的西市－利人市的西口，十字
路口向东，就能走到热闹非凡的西市。西面是一家打铁的铺子，不断的
有“乒乓”-“乒乓”的声音传来。
LONG);

  set("exits", ([ 
  "north":__DIR__"gmdajie7",
  "south":__DIR__"xishixikou2",
 "west":__DIR__"tiejiangpu",
 "east":__DIR__"xishixijie2",
        ]));
  set("objects",([
         __DIR__"npc/youke":1,
         ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

