//雷霆锤法 
//霹雳雷霆
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 30

int perform(object me,object target)
{ 
    object weapon;
    string msg;
    int damage;
        
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
   if(!me->is_fighting())
	   return notify_fail("「霹雳雷霆」只能在战斗中使用!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="hammer")
    return notify_fail("手中无锤，如何施展「霹雳雷霆」？\n");
    if(weapon->query("flag")==1)
		return notify_fail("断掉的兵刃如何使用？\n");
    if(!me->query_skill("leiting-chuifa",1))
    return notify_fail("不会雷霆锤法如何能使出「霹雳雷霆」？\n");
    if((int)me->query("max_force",1)<1500)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("hammer",1)<160)
    return notify_fail("你的基本锤法太差了！\n");
    if((int)me->query_skill("leiting-chuifa",1)<160)
    return notify_fail("你的雷霆锤法还不到家！\n");
    if((int)me->query_skill("bihai-force",1)<150)
    return notify_fail("你的「碧海神功」还不到家！\n");
    
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展「霹雳雷霆」！\n");
    if(me->query("perform_quest/pili")
      &&time()-me->query_temp("perform_busy")<10)
      return notify_fail("连续施展「霹雳雷霆」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    if(!me->query("perform_quest/pili")
      &&time()-me->query_temp("perform_busy")<5)
      return notify_fail("连续施展「霹雳雷霆」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points");
    
    if(!me->query("perform_quest/pili"))
    damage=damage/3;
    else
    damage=damage+damage/3;
    
    msg=HIW"$N"+HIW+"跃空而起，手中$w"+HIW+"一转顺势一招，大喝「"+HIC+"霹"+HIW+"」朝$n"+HIW+"的$l砸去！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「霹雳雷霆」只能在战斗中使用!\n");
    
    msg=HIG"$N"+HIG+"紧跟着快步跟上，右手$w"+HIG+"招数凝重如山，大喝「"+HIC+"雳"+HIG+"」朝$n"+HIG+"的$l砸去！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「霹雳雷霆」只能在战斗中使用!\n");
    
    msg=HIR"$N"+HIR+"双锤一震，手中$w"+HIR+"化繁为简，大喝「"+HIC+"雷"+HIR+"」朝$n"+HIR+"的$l处打去！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「霹雳雷霆」只能在战斗中使用!\n");
    
    msg=HIB"$N"+HIB+"身走轻灵，手中$w"+HIB+"团团飞舞，大喝「"+HIC+"霆"+HIB+"」直砸$n"+HIB+"的$l！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    me->set_temp("perform_busy",time());
    return 1;   
  
 }  

