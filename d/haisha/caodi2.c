
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里是一片草地。一阵风吹来，在海风中夹杂了泥草的气息，你不
觉得一阵舒服。
LONG);

  set("exits", ([ 
 "north":__DIR__"xiaolu1",
  "south":__DIR__"shalu",
       ]));
  set("objects",([
	  __DIR__"npc/youqiuyan":1,
	  ]));
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

