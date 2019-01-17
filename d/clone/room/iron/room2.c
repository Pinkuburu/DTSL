#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","峡谷");
  set ("long", @LONG
映入眼帘的是一片奇石异树，形态直另人叹为观止，阳光照在谷内
的薄雾中映出淡淡的七彩，不时有美丽的蝴蝶在花丛中偏偏起舞，间或
有些奇异的小动物从石缝中探出头来好奇的看着你，微风徐徐吹过，让
人心旷神怡，无比舒畅。
LONG);
  
  set("exits",([
   "up":"/d/changan/shanyao",
   ]));
  set("no_fight",1);
  set("no_exert",1);
  
  setup();

}

void init()
{
	add_action("do_search","search");
}

int do_search()
{
	object me,ob;
	
	me=this_player();
		
	if(me->is_busy())
                return notify_fail("你正在四处乱摸呢！\n");
	if(me->is_fighting())
		return notify_fail("你还是先打完仗再说吧！\n");
	if(me->query("vocation")!="铁匠")
		return notify_fail("你什么也找不到。\n");
	if(me->query_skill("duanzao-jishu",1)<60)
		return notify_fail("你什么也找不到。\n");
	if(time()-query("no_kaicai")<60*30)
		return notify_fail("你什么也没找到。\n");
	message_vision("$N在四周的草丛里摸来摸去。\n",me);
	me->start_busy(3);
	me->receive_damage("sen",50+random(5));
		
	set("no_kaicai",time());
	
        if(random(100)<80){
	 message_vision("$N什么也没找到。\n",me);
	 return 1;
	}
	
	ob=new(__DIR__"obj/tiekuang2");
	if(!ob->move(me)){
	  ob->move(environment(me));
	  tell_object(me,"你负重过多了！\n");
	}
	message_vision("$N眼睛一亮，在草丛中发现一块不同寻常的石头，$N马上看出\n"+
	               "这是一块可以练制上等兵器的奇石，急忙拣了起来。\n",me);
		
	return 1;
}
