
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","英雄酒楼");
  set ("long", @LONG
这里是襄阳的最著名的酒楼。据说英雄好汉路过襄阳，都要来这里
喝点酒。只见几个江湖豪客正在推杯换盏，已经喝得有些酩酊大醉了。
店小二正在那里招呼着进来的客人，老板在柜台处算着账。
LONG);

  set("exits", ([ 
 "west":__DIR__"nandajie2",
        ]));
 set("objects",([
	 __DIR__"npc/chen":1,
__DIR__"npc/xiaoer4":1,
	 ]));
 set("resource/water",1);
  set("valid_startroom", 1);
  setup();
 
}

