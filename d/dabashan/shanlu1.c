
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是条山路。南边是个山脊。北边是一个采石的地方。你小心翼
翼地走着，以免不小心掉了下去。
LONG);

  set("exits", ([ 

   "southdown":__DIR__"shanji1",
   "north":__DIR__"shanya",
   "northeast":"/d/job/yishengjob/shenshan",
   "northwest":__DIR__"caishichang",
//   "northwest":__DIR__"qiaobi",
       ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

