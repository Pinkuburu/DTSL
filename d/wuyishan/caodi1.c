
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里是一片草地。走在柔软的草地之上，你不觉得非常地舒服。北
边有一片树林。南边是一个断崖，已经没有路了。
LONG);

  set("exits", ([ 

   "north":__DIR__"shulin1",
               ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

