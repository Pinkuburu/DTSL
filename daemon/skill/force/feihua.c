//飞花流水。
//飞花。

#include <ansi.h>
#include <skill.h>
		
int exert(object me, object target)
{
	
	string msg;
	int ap,vp;
	
	if(target==me)
			return notify_fail("「飞花」只能用来攻击别人！\n");
	if(!me->is_fighting(target))
	 return notify_fail("这不是你战斗的目标！\n");
	if(environment(me)->query("no_fight"))
	return notify_fail("这里不能使用这么有威胁力的内功！\n");
	if(environment(me)->query("sleep_room"))
	return notify_fail("你不要吵醒别人了！\n");
		
	if(me->query("pker"))
	return notify_fail("通缉犯还是老实点吧！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if(!me->query_skill("flower-force",1))
		return notify_fail("不学飞花流水如何使用「飞花」？\n");
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
	if(time()-me->query_temp("exert_busy/feihualiushui")<5)
          return notify_fail("连续施展绝技需要深厚的先天真气支持，你修为不够，如何能行？\n");
		
	me->add("force",-200);
	
	msg=HIG"$N"+HIG+"飞速晃动，瞬间变成了几个人影！\n"NOR;
	
	ap=me->query_skill("flower-force",1);
	vp=target->query_skill("force",1);
	
	if(random(ap+vp)>vp){
	   msg+="\n$n觉得头脑有些发晕，动作有些迟缓了！\n\n";
	   target->start_busy(3);
	}
	else{
	   msg+="\n$n收敛心神，静静等待着$N的出手。\n\n";
	}
	
	message_vision(msg,me,target);
	
	me->set_temp("exert_busy/feihualiushui",time());
	
	return 1;
}

