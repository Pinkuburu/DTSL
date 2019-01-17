
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","常安坊");
  set ("long", @LONG
这里是长安城西南面的主要居民住宅区，均是规制宽宏的大宅院，
院落重重，拥有天井厢堂。坊巷内的民居则为瓦顶白墙，单层构筑列成
街巷的联排。宅门多作装修讲究的瓦木门，高墙深院，巷道深长，与热
闹的大街迥然有异，宁静祥和。
LONG);

  set("exits", ([ 
   "east":__DIR__"xishixikou2",
        ]));
  set("objects",([
         __DIR__"npc/baixing":2,
         ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

