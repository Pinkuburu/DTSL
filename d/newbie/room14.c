
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","任务篇");
  set ("long", @LONG
对于一个侠客的成长，任务是不可缺少。你可以使用 help job 来
查看目前的任务。对于一个新人，如果你选择的门派距离洛阳比较近，
建议去做禅院的初级任务。如果较远，还是做自己本门派的初级任务好。
LONG);

  set("exits", ([ 
 "west":__DIR__"room13",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

