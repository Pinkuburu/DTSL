
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","凉亭");
  set ("long", @LONG
这里是个凉亭。东面就是宋家堡的练武场了。不时传来呼喝的声音。
凉亭的柱子上画了很多精美的壁画，均是出自优秀的工匠之手。
LONG);

  set("exits", ([ 

   "west":__DIR__"yuedongmen",
   "east":__DIR__"wuchang",
       ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

