
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东宫仆");
  set ("long", @LONG
这里就是东宫仆了，是专门办理和太子有关的一切事务的部门，太
子是国家的未来，一切都不能马虎。所以从太子的策立，培养，监督等
工作都耀这里来负责。
LONG);

  set("exits", ([ 
 "west":__DIR__"tianjie1",
 
        ]));
  set("valid_startroom", 1);
  setup();
 
}

