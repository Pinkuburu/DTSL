
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"雅室"NOR);
  set ("long", @LONG
这里是个雅室。是曼清院的主人上官龙休息的地方。这里有很多美
女在伺候上官龙。这里布置的富丽堂皇。
LONG);

  set("exits", ([ 
	  "down":__DIR__"nanlou",
  ]));
  set("objects",([
	  __DIR__"npc/shangguan-long":1,
  ]));

  set("valid_startroom", 1);
  setup();
 
}
