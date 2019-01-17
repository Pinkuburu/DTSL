
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
你走在一条山路上，南边就是武夷山的上山之路了。两边是秀丽的
风光，隐约可以听到哗哗流水的声音。路旁不时蹦过一只野兔。
LONG);

  set("exits", ([ 

   "southup":__DIR__"shanlu2",
   "northdown":__DIR__"shanjiao",
   "west":__DIR__"shulin1",
          ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

