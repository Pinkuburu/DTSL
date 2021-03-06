//纵横。
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -125

int perform(object me,object target)
{ 
   object weapon;
   int damage,flag;
   string msg;
   
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
   if(!me->is_fighting())
	   return notify_fail("「纵横」只能在战斗中使用！\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="blade")
    return notify_fail("手中无刀，如何使用「纵横」？\n");
	if(weapon->query("flag")==1)
		return notify_fail("断掉的兵刃如何使用？\n");
    if(!me->query_skill("badao"))
    return notify_fail("不学霸刀刀法如何使用「纵横」？\n");
    if((int)me->query("max_force",1)<1500)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("blade",1)<110)
    return notify_fail("你的基本刀法太差了！\n");
    if((int)me->query_skill("badao",1)<110)
    return notify_fail("你的霸刀刀法还不到家！\n");
    
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展出「纵横」！\n");
    
    if(me->query("perform_quest/badao")
      &&time()-me->query_temp("perform_busy")<10)
      return notify_fail("连续施展「纵横天下」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    if(!me->query("perform_quest/badao")
      &&time()-me->query_temp("perform_busy")<8)
      return notify_fail("连续施展「纵横天下」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/badao")){
     damage=damage/2;
     flag=0;
    }else flag=1;
    
    
    msg=HIR"$N"+HIR+"一声长笑，反手拔出背上$w"+HIR+"，以右手拿着，$w"+HIR+"闪烁生辉，好似反映着天上的月色，\n"+
        "随便一站，流露出一股气吞河岳的威势和出于自然的悍勇气质，阵阵强大无伦的杀气。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「纵横」只能在战斗中使用！\n");
    
    if(me->query_skill("badao",1)<130){
    	me->set_temp("perform_busy",time()-2);
        return notify_fail("你的刀法修为不足，目前只能出一招纵横！\n");
    }
    
    msg=HIY"$N"+HIY+"前跨一步，$w"+HIY+"由横摆变成直指，强大和森寒彻骨的刀气朝$n"+HIY+"狂涌而来。心中涌起冲\n"+
        "天豪气，就如驰骋沙场，杀于千军万马之间的壮烈情怀，一声长啸，离地而起，疾若\n"+
        "闪电般往$n"+HIY+"掠去。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「纵横」只能在战斗中使用！\n");
    
    if(me->query_skill("badao",1)<150){
    	me->set_temp("perform_busy",time()-2);
        return notify_fail("你的刀法修为不足，目前只能出两招纵横！\n");
    }
    
    msg=HIG"$N"+HIG+"微一点头，猛地加速前冲，左手$w"+HIG+"化作一道长虹，往$n"+HIG+"电射而去。凌厉凶毒之极，\n"+
        "最惊人处是使人感到这一刀聚集了$N"+HIG+"全身功力，若$n"+HIG+"功力稍逊的话，一刀便可分出胜\n"+
        "败。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「纵横」只能在战斗中使用！\n");
    
    if(me->query_skill("badao",1)<170){
    	me->set_temp("perform_busy",time());
        return notify_fail("你的刀法修为不足，目前只能出三招纵横！\n");
    }
    
   
    if(!flag){
    	me->set_temp("perform_busy",time());
    	return 1;
    }
    me->set_temp("perform_busy",time());
    call_out("perform2",3,me,target,weapon,damage);
    
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
	   
    msg=WHT"$N"+WHT+"一声长啸，立时排除万念，心与神合，灵台不染一尘，$w"+WHT+"由快转缓，似变成重若泰\n"+
        "山般慢慢举起，这玄妙无比的举刀动作，似乎地把方圆丈许内的空气全抽空了，还有\n"+
        "种慑吸着$n"+WHT+"心神的气势，使$n"+WHT+"不但不敢进攻，连退后也有所不能。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「纵横」只能在战斗中使用！\n");
    
    if(me->query_skill("badao",1)<190){
    	me->set_temp("perform_busy",time());
        return notify_fail("你的刀法修为不足，目前只能出四招纵横！\n");
    }
    
    msg=HIR"$N"+HIR+"大喝一声，运劲一振手上$w"+HIR+"，立时发出一种金属鸣响之音，$w"+HIR+"在阳光下寒芒闪闪，\n"+
        "耀人眼目。$N"+HIR+"双手抱刀，倏进三步，到踏出第四步，来到$n"+HIR+"丈许处时，全力一刀劈\n"+
        "出！寒光如电，瞬那间来至$n"+HIR+"头顶处。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「纵横」只能在战斗中使用！\n");
    
    if(me->query_skill("badao",1)<210){
    	me->set_temp("perform_busy",time());
        return notify_fail("你的刀法修为不足，目前只能出五招纵横！\n");
    }
    
    msg=HIY"$N"+HIY+"的$w"+HIY+"终举至头顶，在日光下发出令人目眩神迷的闪亮，双目神光如电，罩着$n"+HIY+"，蓦\n"+
        "地狂吼一声，同一时间，$w"+HIY+"化作一道精芒眩目的慑人彩虹，迅如电闪般以没人可看清\n"+
        "楚的速度，照脸往$n"+HIY+"疾劈过去，刀风带起狂飙，却奇异地吸摄着$n"+HIY+"，凛然有君临天下\n"+
        "之威。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
        
    me->set("apply_points",0);
    me->set_temp("perform_busy",time());
    return 1;   
  
}
