
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西大街");
  set ("long", @LONG
这里是襄阳的西大街。北面是一家兵器铺，从那里传来了乒乒乓乓
的敲打声。南面是一家小吃店，只见店小二正在门口热情地招呼着来往
的客人。
LONG);

  set("exits", ([ 
 "east":__DIR__"xidajie3",
 "west":__DIR__"xidajie1",
 "north":__DIR__"bingqipu",
 "south":__DIR__"xiaochidian",
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

