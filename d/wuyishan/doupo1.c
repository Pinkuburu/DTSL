
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","陡坡");
  set ("long", @LONG
这里是一个陡坡，你不禁小心起来。北边有一条小溪，从这里可以
隐约听到哗哗地流水声。西边有一片树林。
LONG);

  set("exits", ([ 

   "northeast":__DIR__"xiaoxi1",
   "west":__DIR__"shulin4",
   "southdown":__DIR__"doupo2",
   
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

