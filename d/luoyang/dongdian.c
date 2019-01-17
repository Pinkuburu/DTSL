
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"万德殿"NOR);
  set ("long", @LONG
这里是洛阳皇宫的东殿万德殿了。这里虽然不如大殿豪华，但也可
以说富丽堂皇。四周摆设着珍奇古玩，雕栏玉砌，一派尊贵的气氛。平
时皇帝很少来这里，所以这里显得比较清净。出了东殿就是御膳房了。
LONG);

  set("exits", ([ 
  "north":__DIR__"yushanfang",
  "east":__DIR__"eastdoor",
  "west":__DIR__"zijindian",
         ]));
  set("objects",([
	  __DIR__"npc/duguba":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

