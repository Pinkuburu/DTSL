//清心普善诀。
#include <ansi.h>
#include <skill.h>
		
int exert(object me, object target)
{
	int last_time;
	
	if(target!=me)
			return notify_fail("你只能对自己使用清心！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
        if((int)me->query_skill("qingxin-force",1)<120)
		return notify_fail("你的清心普善诀修为不够！\n");
	if((int)me->query_skill("force",1)<100)
		return notify_fail("你的基本内功修为不够！\n");
        if(me->query("force")<200)
		return notify_fail("你的内力不足以使用此内功！\n");
	if(me->query_temp("execute_qingxinforce"))
	return notify_fail("你正在使用清心普善诀！\n");
	if(time()-me->query_temp("execute_qingxinforce_busy")<10)
          return notify_fail("连续施展绝技需要深厚的先天真气支持，你修为不够，如何能行？\n");
	message_vision(MAG"$N"+MAG+"深吸了一口气，身行顿时变得灵活异常！\n"NOR,me);
	me->add_temp("apply/dodge",me->query_skill("qingxin-force",1)/7);
  me->add("force",-200);
	me->set_temp("execute_qingxinforce",1);
	
	last_time=me->query_skill("qingxin-force",1)/3;
	if(last_time>=70) last_time=70;
	
  call_out("cancel_exert",last_time,me,
        me->query_skill("qingxin-force",1)/7);
	return 1;
}

int cancel_exert(object me,int i)
{
  if(!objectp(me))
  return 1;
  me->add_temp("apply/dodge",-i);
  message_vision(HIY"$N"+HIY+"长嘘了一口气，气色恢复平常。\n"NOR,me);
  me->delete_temp("execute_qingxinforce");
  me->set_temp("execute_qingxinforce_busy",time());
  return 1;
}
