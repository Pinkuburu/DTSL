
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","洛神大街");
  set ("long", @LONG
这里是洛阳的洛神大街。这里已经很繁华了。在战乱时期，由于王
世充治城有方，所以洛阳相当的繁华。这里人来人往，北面就是洛阳之
主王世充的王府。
LONG);

  set("exits", ([ 
  
  "east":__DIR__"tianjie2",
  "west":__DIR__"luoshenjie2",
  "north":__DIR__"wangfu",
         ]));
  set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

