
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南门");
  set ("long", @LONG
这里是襄阳城的南门。自古以来襄阳就是军事重地。所以这里的检
查也是非常严格。有几个官兵耀武扬威地站在那里，对进城的人不住地
呼喝。
LONG);

  set("exits", ([ 
 "north":__DIR__"nandajie4",
 "south":__DIR__"guanlu3",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(me->query_temp("guanchai_yunyan")&&dir=="north"&&!present("gong han",me)&&!me->query_temp("no_in"))
	{
		me->apply_condition("yunyan_job",0);
		me->set_temp("no_in",1);
		return notify_fail("有官兵喊道："+RANK_D->query_respect(me)+",运盐进城要先和上级说明一下，等一会吧!\n");
	}
	else if(me->query_temp("guanchai_yunyan")&&dir=="north"&&!present("gong han",me))
		
		return notify_fail("有官兵喊道："+RANK_D->query_respect(me)+",运盐进城要先和上级说明一下，等一会吧!\n");
	if(me->query_temp("guanchai_yunyan")&&dir=="south"&&!present("gong han",me))
	{
		return notify_fail("有官兵喊道："+RANK_D->query_respect(me)+",别走啊，一会就给你公函了!\n");
	}
	return ::valid_leave(me,dir);
}
