
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","碧峰峡");
  set ("long", @LONG
这里峰峦叠嶂，云雾弥漫。密林浓荫将山体打扮得清翠欲滴，白练
似的瀑布又为宁静的青山奏响清悠的乐章。峡内林木葱郁，苍翠欲滴，
峰峦叠嶂，崖壑峥嵘。时而奇峰耸峙，高插蓝天，时而两山并合天光一
线，多类型的瀑布景观，更使双峡增添无限景色，令人陶醉。谷底溪流
奔泻，激发的银色浪花与山谷鸣响，别有一番意境。 
LONG);

  set("exits", ([ 
 "east":__DIR__"shanlu3",
      ]));
  set("objects",([
       ]));
 set("valid_startroom", 1);
  setup();
 
}

