
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short",HIG"正厅"NOR);
  set ("long", @LONG
这里是宋家堡的正厅了。厅上悬挂一个牌匾，上书三个大字「宋家
堡」。笔画锋利，看似含有刀法的招数，更增添了宋家堡的气派。厅的
正前方放着一把大椅子，两旁个放着一排小椅子。这里气氛肃穆，非常
寂静。
LONG);

  set("exits", ([ 

  "north":__DIR__"changlang2",
  "west":__DIR__"xilang1",
  "east":__DIR__"donglang1",
"up":"/d/clone/room/lingwu/lingnan/baihutang",
  "southwest":__DIR__"changlang3",
  "southeast":__DIR__"yuedongmen",
        ]));

  set("valid_startroom", 1);
  
  setup();
  "/obj/sboard/songjia_b.c"->foo();
 
}

