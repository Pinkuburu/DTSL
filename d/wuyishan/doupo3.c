
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","陡坡");
  set ("long", @LONG
这里是一个陡坡，北边就是武夷山了。从这里上去，就可以到武夷
山。这里的山路比较险峻，你不禁小心起来。
LONG);

  set("exits", ([ 

   "westup":__DIR__"doupo2",
   "eastdown":"/d/dongming/xiaolu1",
   
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

