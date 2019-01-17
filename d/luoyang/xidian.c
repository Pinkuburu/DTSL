
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"安平殿"NOR);
  set ("long", @LONG
这里是洛阳皇宫的西殿安平殿了。这里虽然不如大殿豪华，但也可
以说富丽堂皇。四周摆设着珍奇古玩，雕栏玉砌，一派尊贵的气氛。平
时皇帝很少来这里，所以这里显得比较清净。出了西殿就是西门了。
LONG);

  set("exits", ([
  "north":__DIR__"guanhuayuan",
  "east":__DIR__"zijindian",
  "west":__DIR__"westdoor",
         ]));
  set("objects",([
      __DIR__"npc/dugufeng":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

