
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"楼屋"NOR);
  set ("long", @LONG
这里是小楼的一间屋子。这里装饰的并不华丽，但显得超凡脱俗，
气派不凡。
LONG);

  set("exits", ([ 

	  "down":__DIR__"xiaolou",
 ]));

set("objects",([ __DIR__"npc/lumiaozi":1,]));
  
  set("valid_startroom", 1);
  setup();
 
}

