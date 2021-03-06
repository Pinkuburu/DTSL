//伏魔杖法。
//金刚伏魔。

#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -100

int perform(object me,object target)
{ 
    object weapon;
    string msg;
    int damage;
    
    if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
    
   if(!me->is_fighting())
	   return notify_fail("「金刚伏魔」只能在战斗中使用!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="staff")
    return notify_fail("手中无杖，如何使用「金刚伏魔」？\n");
    if(weapon->query("flag")==1)
		return notify_fail("断掉的兵刃如何使用？\n");
    if(me->query("PKS")>=5)
        return notify_fail("你罪孽深重，无法使用此绝技了！");
    if(!me->query_skill("fumo-zhangfa"))
    return notify_fail("不学伏魔杖法如何使用「金刚伏魔」？\n");
    if((int)me->query("max_force",1)<1000)
    return notify_fail("你的内力修为太低了！\n");
    if((int)me->query_skill("staff",1)<110)
    return notify_fail("你的基本杖法太差了！\n");
    if((int)me->query_skill("fumo-zhangfa",1)<110)
    return notify_fail("你的伏魔杖法还不到家！\n");
    if((int)me->query_skill("wuxiang-shengong",1)<100)
    return notify_fail("你的「无相神功」还不到家！\n");
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展出「金刚伏魔」！\n");
    if(me->query("perform_quest/fumo")
      &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("连续施展「金刚伏魔」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    if(!me->query("perform_quest/fumo")
      &&time()-me->query_temp("perform_busy")<5)
       return notify_fail("连续施展「金刚伏魔」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points");
    if(!me->query("perform_quest/fumo"))
    damage=damage/2;
	
    msg=HIG"$N"+HIG+"手中的$w"+HIG+"简简单单的一下横扫，内中实含无数变化后着，配上奇异玄妙的步法，\n"+
        "实是不易招架。厉害的是$w"+HIG+"由缓而快，带起的气劲把$n"+HIG+"完全笼罩在内，务要令$n"+HIG+"不能\n"+
        "脱身。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「金刚伏魔」只能在战斗中使用！\n");
    
    msg=YEL"$N"+YEL+"面色沉稳，手中$w"+YEL+"招式缓慢，但却似乎是含有千钧之力。$n"+YEL+"全身被$N"+YEL+"凝重的气势笼罩，\n"+
        "眼睁睁的瞧著$w"+YEL+"向自己的$l砸过来，偏是无法躲避！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「金刚伏魔」只能在战斗中使用！\n");
    
    msg=HIC"$N"+HIC+"的攻势突然变得凌厉，攻的虽只是$w"+HIC+"所取的一点，但却把$n"+HIC+"完全笼罩，使他生出无\n"+
        "法躲闪的感觉，在气机牵引下，$n"+HIC+"更有一种宿手就擒的迹象！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「金刚伏魔」只能在战斗中使用！\n");
    
    if(!me->query("perform_quest/fumo")){
    	me->set_temp("perform_busy",time());
        return 1;
    }
    
    msg=HIY"$N"+HIY+"双目微睁，其中精芒烁动，仍予人神藏内敛的含蓄，缓缓举起$w"+HIY+"，直至头顶，一股旋\n"+
        "劲立即以他为中心卷起，地上的草叶均环绕他狂旋飞舞，低喝一声“阿弥陀佛”！\n"+
        "只见$w"+HIY+"从$N"+HIY+"手中飞出直朝$n"+HIY+"的$l处砸去！\n"NOR;
    
    damage += damage/3;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    msg="\n$N一探手，接住了"+weapon->name()+"！\n";
    message_vision(msg,me);
   
    me->set_temp("perform_busy",time());
    return 1;   
  
}  

