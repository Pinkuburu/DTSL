
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山峰");
  set ("long", @LONG
这里是武夷山的一座山峰。下面是茫茫的深谷。从这里看去，武夷
山秀丽的风光尽收眼底，一股豪壮的感觉油然而生。
LONG);

  set("exits", ([ 

   "west":__DIR__"shulin3",
    
          ]));
set("objects",([
 "/d/clone/npc/beast/shanyang":1,
]));
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

