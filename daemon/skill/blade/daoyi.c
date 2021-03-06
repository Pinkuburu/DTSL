//刀意
#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
     int i;
     int last_time;
     object weapon;
     
     
     weapon=me->query_temp("weapon");	
    if(!weapon||weapon->query("skill_type")!="blade")
    return notify_fail("手中无刀，如何使用「刀意」？\n");
        if(weapon->query("flag")==1)
                return notify_fail("断掉的兵刃如何使用？\n");
     if(me->query_temp("perform_tdbj"))
    return notify_fail("你正在使用天刀八决。\n");
    if(!me->query_skill("tiandao-bajue",1))
    return notify_fail("不学「天刀八决」如何使用「刀意」？\n");
    if(!me->is_fighting())
    return notify_fail("「刀意」只能在战斗中使用！\n");
    if((int)me->query("max_force")<1200)
    return notify_fail("你的内力修为太低了!\n");
    if((int)me->query("force")<200)
    return notify_fail("你的内力不够使用此招数!\n");
    if((int)me->query_skill("tiandao-bajue",1)<100)
    return notify_fail("你的天刀八决太差了！\n");
    if((int)me->query_skill("blade",1)<100)
    return notify_fail("你的基本刀法还不到家！\n");
    if(me->query_skill("wangdao-jue",1)<100)
    return notify_fail("你的忘刀诀修为太低了！\n");
    if(me->query_skill("tiangang-sanjue",1)<100)
    return notify_fail("你的天罡三诀修为太低了！\n");
    
    if(time()-me->query_temp("perform_busy_daoyi")<15)
    return notify_fail("你真气不足，无法施展「刀意」！\n");
    
message_vision(HIC"$N"+HIC+"暗运真气，手中"+weapon->name(me)+HIC+"直指$n"+HIC+"，天刀八决的刀意被$N"+HIC+"发挥的淋漓尽致！\n"NOR,me,target);
    i=me->query_skill("tiandao-bajue",1)/10;
    me->add_temp("apply/damage",i);
    me->set_temp("perform_tdbj",1);
    me->add("force",-200);
    
    last_time=me->query_skill("tiandao-bajue",1)/3;
    if(last_time>=70) last_time=70;
    
    call_out("rid_attack",last_time,me,i);
    return 1;   
  
}  
 
void rid_attack(object me,int i)
{
  if(!me) return;
  message_vision(HIB"\n$N"+HIB+"催动的真气慢慢消散，无法在保持刀意的境界了。\n"NOR,me);
  me->add_temp("apply/damage",-i);
  me->delete_temp("perform_tdbj");
  me->set_temp("perform_busy_daoyi",time());
  return;
}
