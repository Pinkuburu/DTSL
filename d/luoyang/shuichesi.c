
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","水车肆");
  set ("long", @LONG
由于洛阳占地广大，即使几条大河穿插其间，仍然避免不了火灾的
危险，因此洛阳仍然备有官方的水车肆，执行战时和平时的救火任务。
LONG);

  set("exits", ([ 
      "east":__DIR__"qinglongjie1",
  ]));
  set("valid_startroom", 1);
  setup();
 
}

