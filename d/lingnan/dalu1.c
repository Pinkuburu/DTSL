
#include <ansi.h>
#include <job_money.h>
inherit ROOM;


void create ()
{
  set ("short","大路");
  set ("long", @LONG
这里是一个宽敞的大路。迎面的是一条笔直大道，道边种有青青杨
柳树，随风飘扬。南边隐隐约约可以看到一个城堡似的建筑物。
LONG);

  set("exits", ([ 

  "northwest":__DIR__"caodi1",
  "south":__DIR__"dalu2",
         ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

