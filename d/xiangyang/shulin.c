
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这是黑森森的一片密林，楠木参天，浓阴蔽日。鲜花绿草若隐若现，
随着山谷里吹来的阵阵清风，传来哗哗的松涛声和一些淡淡的花香，身临
其境，古朴、幽静之感油然而生。
LONG);

  set("exits", ([ 
  "northeast":__DIR__"shulin1",
  "south":__DIR__"caodi3",
         ]));

  set("valid_startroom", 1);
  set("outdoors","xiangyang");
  setup();
 
}

