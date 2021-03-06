//飞挝鞭法
//困兽囚笼

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 50


int perform(object me,object target)
{ 
    object weapon;
    int damage,flag=0;
    string msg;
    
    weapon=me->query_temp("weapon");
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
    
   if(!me->is_fighting())
   return notify_fail("「困兽囚笼」只能在战斗中使用！\n");
   if(!weapon)
    return notify_fail("不拿武器，如何使用「困兽囚笼」？\n");
   if(weapon->query("skill_type")!="whip")
    return notify_fail("不拿鞭子，如何使用「困兽囚笼」？\n");
    if(weapon->query("flag")==1)
		return notify_fail("断掉的兵刃如何使用？\n");
    if(!me->query_skill("feiwo-whip",1))
    return notify_fail("不学[飞挝鞭法]如何使用「困兽囚笼」？\n");
    if(me->query("apply_points")<=0)
    return notify_fail("你的气势不足，无法使用「困兽囚笼」！\n");
    
    if((int)me->query("max_force")<1000)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("whip",1)<110)
    return notify_fail("你的基本鞭法太差了！\n");
    if((int)me->query_skill("feiwo-whip",1)<110)
    return notify_fail("你的「飞挝鞭法」还不到家！\n");
    if((int)me->query_skill("yanyang-dafa",1)<100)
    return notify_fail("你的「炎阳大法」还不到家！\n");
    
    if(me->query("perform_quest/kun")
     &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("连续施展「困兽囚笼」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    if(!me->query("perform_quest/kun")
     &&time()-me->query_temp("perform_busy")<7)
       return notify_fail("连续施展「困兽囚笼」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/kun"))
    	damage=damage/2;//如果没解迷题。
    else
    	damage=damage*2;
    
    msg=HIG"$N"+HIG+"双目寒光大盛，$w"+HIG+"交叉点出，汇成一柱芒流，集中全力往疾退的$n"+HIG+"激射过去，竟比\n"+
        "对手仍要快上一线。$N"+HIG+"战法之高明，招式的狠辣，手法的奇奥，均使人膛目叫绝。\n"NOR;   
    
    flag=COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    
    if(!me->is_fighting())
    return notify_fail("「困兽囚笼」只能在战斗中使用！\n");

    msg=HIY"$N"+HIY+"全身一震，往后移了半步，眼中射出森厉神色，幻出千重幻影，把$w"+HIY+"威力展至极限，将\n"+
        "$n"+HIY+"全卷进点点光彩里，招招皆是精妙绝伦的绝技。\n"NOR;    
        
    flag+=COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「困兽囚笼」只能在战斗中使用！\n");
    
    if(!me->query("perform_quest/kun")){
      if(flag){
      	msg="\n$n被$N击中，浑身一震，行动顿时迟缓了！！\n";
      	message_vision(msg,me,target);
      	target->start_busy(3);      	
      }
      me->set_temp("perform_busy",time());
      return 1;
    }
    
    msg=HIR"$N"+HIR+"右手往后一抽，$w"+HIR+"离身而起，登时森冷侵人，当胸向$n"+HIR+"击去！也不知$N"+HIR+"使了什么手法，\n"+
        "$w"+HIR+"其中一的端脱肩飞出，发出劲历的破空声，疾电般绕了个圈，朝$n"+HIR+"的$l打去，手法阴\n"+
        "毒之极。\n"NOR;
    
    flag+=COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「困兽囚笼」只能在战斗中使用！\n");
    
    if(flag){
      	msg="\n$n被$N击中，浑身一震，行动顿时迟缓了！！\n";
      	message_vision(msg,me,target);
      	target->start_busy(4);      	
    }
    me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
