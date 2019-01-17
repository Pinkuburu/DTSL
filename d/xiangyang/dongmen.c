
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","东门");
  set ("long", @LONG
这里是襄阳城的东门了。襄阳历来都是军事重地，所以有很多官兵
在这里检查来往的行人。只见有几个人正守护着盐车站在那里，等待官
兵发给他们进城的公函。
LONG);

  set("exits", ([ 
"west":__DIR__"dongdajie3",
"east":__DIR__"guanlu1",
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
	if(me->query_temp("guanchai_yunyan")&&dir=="west"&&!present("gong han",me)&&!me->query_temp("no_in"))
	{
		me->apply_condition("yunyan_job",0);
		me->set_temp("no_in",1);
		return notify_fail("有官兵喊道："+RANK_D->query_respect(me)+",运盐进城要先和上级说明一下，等一会吧!\n");
	}
	else if(me->query_temp("guanchai_yunyan")&&dir=="west"&&!present("gong han",me))
		
		return notify_fail("有官兵喊道："+RANK_D->query_respect(me)+",运盐进城要先和上级说明一下，等一会吧!\n");
	if(me->query_temp("guanchai_yunyan")&&dir=="east"&&!present("gong han",me))
	{
		return notify_fail("有官兵喊道："+RANK_D->query_respect(me)+",别走啊，一会就给你公函了!\n");
	}
	return ::valid_leave(me,dir);
}

void give_card(object me)
{
	object card;
	if(!me) {remove_call_out("give_card");return;}
	card=new(__DIR__"obj/card");
	card->move(me);
    message_vision("官兵给了$N一个公函\n",me);
    return;
  //  remove_call_out("give_card");return;
}

