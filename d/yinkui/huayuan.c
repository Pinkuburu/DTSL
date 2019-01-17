
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIR"花园"NOR);
  set ("long", @LONG
这里是一个花园。不过并没有种平常的牡丹，芍药等，而是种了很
多看起来象药材的花，有雪白的，有鲜红的，个个颜色不一，但无一不
是妖娆艳丽，一看就知道是毒花毒草。
LONG);
  set("exits",([
	  "south":__DIR__"xiaoshilu1",
	  "north":__DIR__"guangchang",
	  ]));
  set("objects",([
	  __DIR__"npc/dizi1":1,
      //__DIR__"npc/dizi2":1,
     // __DIR__"npc/changzhen":1,
    ]));
  set("valid_startroom", 1);
  set("outdoors","yinkui");
  setup();
 
}

