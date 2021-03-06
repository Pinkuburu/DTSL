//风雨具来。
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 50

int perform(object me,object target)
{ 
   object weapon;
   int damage,flag;
   string msg;
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
   if(!me->is_fighting())
	   return notify_fail("「风雨具来」只能在战斗中使用！\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="spear")
    return notify_fail("手中无枪，如何使用「风雨具来」？\n");
	if(weapon->query("flag")==1)
		return notify_fail("断掉的兵刃如何使用？\n");
    if(!me->query_skill("fuying-spear"))
    return notify_fail("不学伏鹰枪法如何使用「风雨具来」？\n");
    if((int)me->query("max_force",1)<1000)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("spear",1)<110)
    return notify_fail("你的基本枪法太差了！\n");
    if((int)me->query_skill("fuying-spear",1)<110)
    return notify_fail("你的伏鹰枪法还不到家！\n");
    if(me->query_skill("yanyang-dafa",1)<100)
    return notify_fail("你的炎阳大法修为太低了！\n");
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展出「风雨具来」！\n");
    
    if(me->query("perform_quest/fengyu")
      &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("连续施展「风雨具来」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    if(!me->query("perform_quest/fengyu")
      &&time()-me->query_temp("perform_busy")<5)
       return notify_fail("连续施展「风雨具来」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/fengyu")){
     damage=damage/2;
     flag=0;
    }else flag=1;
    
   
    msg=HIY"$N"+HIY+"的$w"+HIY+"移回前方，只以单手拏着，枪锋遥指对手，左手反负在身后，姿态从容好看。\n"+
        "$N"+HIY+"仰天长笑，手中$w"+HIY+"颤震不休，发出“嗤！嗤！”枪劲，直朝$n"+HIY+"的$l刺去。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「风雨具来」只能在战斗中使用！\n");
    
    
    msg=HIG"$N"+HIG+"在气机牵引下，微往左移半步，手中$w"+HIG+"化为一道精芒，电疾斜刺，角度之妙，恰好比$n"+HIG+"\n"+
        "此际采取的进攻路线要早上一步刺中对手。$w"+HIG+"带起了一阵旋风，倍添其惊人的声势。以$n"+HIG+"\n"+
        "之能，仍料不到$N"+HIG+"变招以攻代守在时间上掌握得如此精到，反击是这般凌厉，枪势浑然天\n"+
        "成。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「风雨具来」只能在战斗中使用！\n");
   
    
    msg=WHT"短短的距离内，$N"+WHT+"的枪法却是变化万千，每一刹那都作着微妙精奇的改变，瞧着$N"+WHT+"变化无\n"+
        "穷的一枪戳至，劲风将$n"+WHT+"完全笼罩，其中气劲强弱分布又不断微妙改动，使人防不胜防，\n"+
        "挡无可挡。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
       
    if(!flag){
    	me->set_temp("perform_busy",time());
    	return 1;
    }
    
    call_out("perform2",3,me,target,weapon,damage);
    me->set_temp("perform_busy",time());
    return 1;   
  
}

int perform2(object me,object target,object weapon,int damage)
{ 
        string msg;
        
        if(!me) return 1;
        if(!target||!living(target)){
         me->set_temp("perform_busy",time());
         return 1;
        }
        me->set_temp("perform_busy",time());
        if(!weapon||me->query_temp("weapon")!=weapon)
        return 1;
        if(me->is_busy())
        return 1;
  
        if(!me->is_fighting(target))
	   return 1;
	   
    msg=MAG"$N"+MAG+"一阵长笑，枪势展开，在眨眼的高速间，连续刺出三枪，每一枪的角度均针对$n"+MAG+"的反应\n"+
        "而略有变化，凶猛无俦。一时万千枪影，把$n"+MAG+"完全笼罩其中。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「风雨具来」只能在战斗中使用！\n");
      
    msg=HIR"$N"+HIR+"眼中神光暴现，手中的$w"+HIR+"倏地刺出，幻成满天枪影，罩向$n"+HIR+"，空气也凝重起来。$n"+HIR+"只觉\n"+
        "的眼前一暗，一眼望去，竟只见一片枪网，遮天盖地而来，仿佛天地间别无他物，一时之\n"+
        "间，心神惧丧，竟无法出招。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
        
    me->set_temp("perform_busy",time());
    return 1;   
  
}
