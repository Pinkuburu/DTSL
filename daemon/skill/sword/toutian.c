//偷天剑法
//偷天
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 110 //命中高

int perform(object me,object target)
{ 
    object weapon;
    string msg;
    int damage,flag;
    
    flag=0;
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
   if(!me->is_fighting())
	   return notify_fail("「偷天」只能在战斗中使用!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="sword")
    return notify_fail("手中无剑，如何使用「偷天」？\n");
    if(weapon->query("flag")==1)
		return notify_fail("断掉的兵刃如何使用？\n");
    if(!me->query_skill("toutian-jianfa",1))
    return notify_fail("不学「偷天剑法」如何使用「偷天」？\n");
    if((int)me->query("max_force",1)<1500)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("sword",1)<160)
    return notify_fail("你的基本剑法太差了！\n");
    if((int)me->query_skill("toutian-jianfa",1)<160)
    return notify_fail("你的「偷天剑法」还不到家！\n");
   
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展「偷天」！\n");
    if(me->query("perform_quest/toutian")
      &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("连续施展「偷天」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    if(!me->query("perform_quest/toutian")
      &&time()-me->query_temp("perform_busy")<5)
       return notify_fail("连续施展「偷天」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points");
    
    if(!me->query("perform_quest/toutian"))
    damage=damage/2;
    
    msg=HIG"$N"+HIG+"倏地踏前三步，右手按往$w"+HIG+"，剑虽仍在鞘内，但人却变得剑锋般锐利，涌起一股凌\n"+
        "厉的剑气，朝$n"+HIG+"激冲过去。$N"+HIG+"的脸容变得无比冷酷，双目闪耀着凝然如有实质的强大\n"+
        "自信，身体像拔天而起的傲松古柏。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「偷天」只能在战斗中使用!\n");
    
    msg=HIY"$N"+HIY+"左右晃动，$w"+HIY+"化作一道变幻莫测的光束，破空而去，此一剑乃$N"+HIY+"全力所聚。倏地剑\n"+
        "往下压，斜指$n"+HIY+"，似攻非攻，似守非守，此剑不但手、眼、步配合得天衣无缝，且令\n"+
        "人感到$N"+HIY+"的剑凝聚全身全灵的力量，意透神聚。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「偷天」只能在战斗中使用!\n");
        
    msg=MAG"$N"+MAG+"嘴角逸出一丝充满奇异魅力的笑容，“锵”的一声清响，右手从鞘内拔出$w"+MAG+"，完全\n"+
        "没有停留犹豫的气贯剑锋，人剑一体，化作长虹，横过四丈的远距离，把握剑的动作\n"+
        "串成一个简单的整体，令人生出玄之又玄的感觉，人剑合一的笔直朝$n"+MAG+"射去。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「偷天」只能在战斗中使用!\n");
    
    if(!me->query("perform_quest/toutian")){    
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
       
    msg=HIW"$N"+HIW+"一声长啸，$w"+HIW+"发出嗡嗡异鸣，斜刺而出，同时往左移开，并猛扭身躯，$w"+HIW+"在怀内爆\n"+
        "起一团因反映四周光线而烁动流转的剑芒，似幻实真的迎上$n"+HIW+"的进攻，“轰”！剑芒\n"+
        "再盛，化作漫天虚虚实实幻影，似水银泻地，无孔不入的往$n"+HIW+"攻去。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「偷天」只能在战斗中使用!\n");
    
    msg=HIR"$N"+HIR+"双目精芒大盛，往横疾闪，漫天钻动如火蛇狂舞的剑芒还原为$w"+HIR+"，老老实实的一剑\n"+
        "横扫，本是平凡不过至乎有些笨拙味道的一剑，却令所有观战者生出千军万马厮杀得\n"+
        "血流成河、尸横片野、日月无光那种惨烈的感觉。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「偷天」只能在战斗中使用!\n");
    
    msg=YEL"$N"+YEL+"的$w"+YEL+"缓缓探直，再高举过头，另一手亦握上剑把，变成双手持剑之势。带起一股强\n"+
        "劲凌厉、聚而不散的剑气，忽的$w"+YEL+"稍往前劈，即改变方向，逆转剑势的在头顶画出一\n"+
        "个完美无瑕的正圆形，把剑气一下子全收在头顶剑圈间的窄小范围内，敛而不散，显\n"+
        "而不逸。动作似缓似快，心意清楚分明。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);
    
    me->set("apply_points",0);
    me->set_temp("perform_busy",time());
    return 1;
}
