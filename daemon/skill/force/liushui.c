//飞花流水。
//流水。

#include <ansi.h>
#include <skill.h>
		
int exert(object me, object target)
{
	
	string msg;
	int last_time;
	
	if(target!=me)
			return notify_fail("「流水」不能用来攻击别人！\n");
	if(environment(me)->query("no_fight"))
	return notify_fail("这里不能使用这么有威胁力的内功！\n");
	if(environment(me)->query("sleep_room"))
	return notify_fail("你不要吵醒别人了！\n");
		
	if(me->query("pker"))
	return notify_fail("通缉犯还是老实点吧！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if(!me->query_skill("flower-force",1))
		return notify_fail("不学飞花流水如何使用「流水」？\n");
	if((int)me->query_skill("flower-force",1)<150)
		return notify_fail("你的飞花流水修为不够！\n");
	if((int)me->query_skill("force",1)<150)
        return notify_fail("你的基本内功修为不够！\n");
	if(me->query("max_force")<1000)
		return notify_fail("你的内力修为不够！\n");
	if(me->query("force")<200)
		return notify_fail("你的内力不足以使用此内功！\n");
	if(me->query_temp("exert_feihualiushui"))
	return notify_fail("你正在使用飞花流水。\n");
	if(time()-me->query_temp("exert_busy/feihualiushui")<10)
          return notify_fail("连续施展绝技需要深厚的先天真气支持，你修为不够，如何能行？\n");
		
	me->add("force",-200);
	
	msg=HIG"$N"+HIG+"微微一笑，只见身法立刻灵活起来，如同行云流水一般！\n"NOR;
	message_vision(msg,me);
	me->set_temp("exert_feihualiushui",1);
	me->add_temp("apply/dodge",me->query_skill("flower-force",1)/3);
	
	last_time=me->query_skill("flower-force",1)/3;
	if(last_time>=70) last_time=70;
	
	call_out("exert2",last_time,
	         me,me->query_skill("flower-force",1)/3);
	
	return 1;
}

int exert2(object me,int armor)
{
   if(!me)
   return 1;
   
   message_vision("\n$N收回了飞花流水。\n\n",me);
   me->add_temp("apply/dodge",-armor);
   me->set_temp("exert_busy/feihualiushui",time());
   me->delete_temp("exert_feihualiushui");
   return 1;
}
