
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里是一片草地。北边偶尔能听到兵器撞击的声音。不时有人从北
面走过来，用怀疑的眼光打量着你。
LONG);

  set("exits", ([ 

  "northeast":__DIR__"bingqiku",
  "south":__DIR__"xiaolu1",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

