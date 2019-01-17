
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"小路"NOR);
  set ("long", @LONG
这里是一条小路，左转右弯，眼前忽地豁然开朗，在临崖的台地上，
建有一座两层小楼，形势险要.
LONG);

  set("exits", ([ 

	  "west":__DIR__"xiaolu5",
	  "east":__DIR__"xiaolou",
  ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

