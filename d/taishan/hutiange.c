
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","壶天阁");
  set ("long", @LONG
这里是泰山的壶天阁。这里景色非常漂亮，向山下望去，一片碧绿，
清风吹来，更是舒服之及。有很多游人在这里休息，谈论着何时才能攀到
泰山的顶端。
LONG);

  set("exits", ([ 

   "eastup":__DIR__"zhongtianmen",
   "southdown":__DIR__"doumugong",
          ]));
  set("objects",([
     __DIR__"npc/shangren":1,
     ]));
set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

