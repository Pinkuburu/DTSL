
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","官路");
  set ("long", @LONG
这里是长安城的西门外的官路。由于这里是行人通往西方的必经之
路，所以行人还是很多，从这里向东看你就可以看见古城长安了。
LONG);

  set("exits", ([ 
 "east":__DIR__"ximen",
 "west":__DIR__"guandao2",
        ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

