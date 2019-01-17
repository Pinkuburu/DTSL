
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","白鹤泉");
  set ("long", @LONG
这里是泰山的白鹤泉。它的水清凉甘甜，为泰山之最。这泉水长年
涌流不断，喷出的水象仙鹤扑扇着翅膀洗澡一样，因此命名为白鹤泉。
这里就是开始攀登泰山的路了。
LONG);

  set("exits", ([ 

   "down":__DIR__"daizongfang",
   "eastup":__DIR__"shanlu1",
          ]));
 /*set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("resource/water",1);
set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

