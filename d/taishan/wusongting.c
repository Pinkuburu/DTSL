
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","五松亭");
  set ("long", @LONG
这里是泰山的五松亭。来到这里，你觉的想休息一下。在这里休息
的游人很多，也有来磨练自己的侠客。
LONG);

  set("exits", ([ 

   "westup":__DIR__"bixiaci",
   "westdown":__DIR__"yunbuqiao",
          ]));

set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

