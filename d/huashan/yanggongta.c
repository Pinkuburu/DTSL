
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","高塔");
  set ("long", @LONG
这里是有一座高塔，塔身六面，高有六层。站在塔上，可以看到华
山秀丽的风光。塔内有许多名人的字迹，均为赞颂华山之词。四周景色
郁郁葱葱，尽收眼中，令人不由得豪气顿生。
LONG);

  set("exits", ([ 
 "southup":__DIR__"yunvfeng",
 "northwest":__DIR__"xianzhangya",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
  set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
