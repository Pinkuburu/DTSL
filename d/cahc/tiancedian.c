
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","天策殿");
  set ("long", @LONG
自从李世民立了大功，受李渊封赏成立天策府后，这所大殿就改名
为天策殿，平日为天策府诸将议事之处。大殿平面为方形，深、广各三
间，单檐四角攒尖顶，铜镀金宝顶，黄琉璃瓦，双昂五踩斗栱，梁枋饰
龙凤和玺彩画。
LONG);

  set("exits", ([ 
 "north":__DIR__"houdian",
 "southdown":__DIR__"tcgc",
 "east": "/d/clone/room/orgsaferoom/lifa/baihutang",
        ]));
set("objects",([
	  "/d/changan/npc/fangxuan-ling":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 "/obj/sboard/lifa_b.c"->foo();
  
}

