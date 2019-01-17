
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","朱雀门");
  set ("long", @LONG
这里是皇城的南大门，高十多丈，平面矩形。基部为青色大理石须
弥座，城台辟门洞三座，上建城楼。门前三十余步有建筑一座，也是青
色巨石搭建，上方分五层分布了数个窗口，隐隐有士兵的影子在窗口中
晃动，此建筑名曰“箭楼”。 
LONG);

  set("exits", ([ 
 "north":__DIR__"tianjie1",
 "south":"/d/changan/guangchang",
 "west":__DIR__"hanguangmen",
 "east":__DIR__"anshangmen",
        ]));
  set("objects",([
	  "/d/changan/npc/bing":4,
	  ]));

  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

