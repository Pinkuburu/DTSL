
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"柴薪铺"NOR);
  set ("long", @LONG
按道理一般的柴薪铺不应该出现在天街的旁边，但是这个柴薪铺与
众不同，它所提供的是皇亲国戚所使用的烧柴，自然高贵一些，所以被
安置在这里。
LONG);

  set("exits", ([ 
      "west":__DIR__"tianjie",
  ]));

  set("valid_startroom", 1);
  setup();
 
}

