
#include <ansi.h>
inherit ROOM;

int do_dig();
void create ()
{
  set ("short","花园");
  set ("long", @LONG
这里是个花园。这里的花的品种不是很多，但是种了很多珍贵的药
材。各种花五彩缤纷，色彩艳丽，让人赏心悦目。花园的围杆花纹奇特，
必定是出自成都著名工匠之手。
LONG);

  set("exits", ([ 
  
	  "west":__DIR__"donglang2",
	  "southeast":__DIR__"liangting",
        ]));
  set("objects",([
	  __DIR__"npc/nvdizi":2,
	  ]));
  set("dig_out", "/d/chengdu/obj/huangqi");
	
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_dig",({"dig","wa"}));
}

int do_dig()
{
	object me,ob,tool;
	me=this_player();
	if(me->is_busy()||me->is_fighting())
		return notify_fail("你还忙着呢！\n");
	if(!me->query_temp("weapon"))
		return  notify_fail("空手怎么挖药啊？\n");
	tool=me->query_temp("weapon");
	if(tool->query("name")!="锄头")
		return notify_fail("没有锄头怎么挖药？\n");
	message_vision("$N抡起锄头挖起药来。\n",me);
	if(random(10)>4)
	{if(random(4)>1)
		ob=new(__DIR__"obj/huangqi");
	else ob=new(__DIR__"obj/gouqizi");
	me->start_busy(2);
	ob->move(me);
	me->receive_damage("sen",5+random(10));
    message_vision("$N挖到了一个"+ob->name()+"!\n",me);
	return 1;
	}
	message_vision("$N挖了半天，什么也没挖到！\n",me);
	me->receive_damage("sen",5+random(10));
	return 1;
}