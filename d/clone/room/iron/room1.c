#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","矿山");
  set ("long", @LONG
这里是一座矿山。据说这里盛产很多好的矿石，因此许多矿工在这
里开采矿石。不过这里地形险要，非常危险。因此，这里经常出现矿石
砸死矿工的事件。
LONG);

  set("exits",([
    "south":"/d/wuyishan/shulin3",
   ]));
  set("no_fight",1);
  set("no_exert",1);
  
  setup();

}

void init()
{
	add_action("do_cai","kaicai");
}

int do_cai(string arg)
{
	object me,ob,tool;
	
	me=this_player();
	
	if(!arg||arg!="矿石")
		return notify_fail("你想开采什么？\n");
	if(!objectp(tool=me->query_temp("weapon")))
		return notify_fail("空手怎么开采矿石？\n");
	if(tool->query("skill_type")!="fork")
		return notify_fail("你还是用镐头开采吧！\n");
	if(me->is_busy())
		return notify_fail("你现在很忙，歇歇吧!\n");
	if(me->is_fighting())
		return notify_fail("你还是先打完仗再说吧！\n");
	if(time()-query("no_kaicai")<60*30)
		return notify_fail("这里现在没有矿石，你等会再来吧！\n");
	message_vision("$N用"+tool->name()+"开采起矿石来。\n",me);
	me->start_busy(3);
	me->receive_damage("sen",50+random(5));
	
	if(me->query_skill("dodge",1)<120){
	  message_vision("$N被矿石砸了正中！\n",me);
	  me->unconcious();
	}
	
	set("no_kaicai",time());
	
	if(random(100)<95){
	 message_vision("$N什么也没开采到！\n",me);
	 return 1;
	}
	
	ob=new(__DIR__"obj/tiekuang1");
	if(!ob->move(me)){
	  ob->move(environment(me));
	  tell_object(me,"你负重过多了！\n");
	}
	message_vision("$N开采出一块"+ob->name()+"来！\n",me);
		
	return 1;
}
