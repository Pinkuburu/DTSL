//螺旋气劲

#include <ansi.h>

inherit SSERVER;

int exert(object me,object target)
{ 
    
    int flag;
    
    flag=0;
    
   if(!me->is_fighting())
		return notify_fail("「螺旋气劲」只能在战斗中使用!\n");
   if(target==me)
   return notify_fail("「螺旋气劲」只能对别人使用。\n");   
   if(!me->is_fighting(target))
   return notify_fail("这不是你战斗的目标！\n");
    if(!me->query_skill("changsheng-jue",1))
    return notify_fail("不学「长生诀」如何使用「螺旋气劲」？\n");
    if(!me->query("force_quest/csj_ok"))
    return notify_fail("你现在无法施展「螺旋气劲」！\n");
    if(time()-me->query_temp("exert_csj_busy")<20)
    return notify_fail("你真气不足，无法施展「螺旋气劲」！\n");
    
    if((int)me->query("max_force")<2000)
    return notify_fail("你的内力修为太低了！\n");
    
       if((int)me->query("force")<300)
    return notify_fail("你的内力不够使用此招数!\n");
    
    me->add("force",-300);
    
    flag+=COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0,2);
    if(objectp(target))
    flag+=COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0,2);
    if(objectp(target))
    flag+=COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0,2);
    
    if(flag&&objectp(target)){
        target->set_temp("csj_skill_damage",me->query_skill("changsheng-jue",1));
        target->set_temp("csj_damage_time",time());
    }
    
    me->set_temp("exert_csj_busy",time());
    return 1;   
  
}  
 