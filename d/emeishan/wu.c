
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","茅屋");
  set ("long", @LONG
这是一个茅屋，构造简单，或许是为游人的休息而准备的吧。这里
风景秀丽，山水如画，空气清新。远处的地上有很多漂亮的野花、蒲公
英等植物。不时有野兔从你的脚旁跳过。
LONG);

  set("exits", ([ 
  "south":__DIR__"shulin",
       ]));
 set("valid_startroom", 1);
  setup();
 
}

