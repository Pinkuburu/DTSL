//狮子印
#include <ansi.h>

inherit SSERVER;

int perform(object me,object target)
{ 
     int flag,damage;
     string msg;
     object weapon;
     weapon=me->query_temp("weapon");
     
    if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
    if(weapon)
    return notify_fail("拿着武器，如何使用「狮子印」？\n");
    if(!me->is_fighting())
    return notify_fail("只有在战斗时才可以使用「狮子印」。\n");
    if(!me->query_skill("jiuzi-zhenyan",1))
    return notify_fail("不学「九字真言」如何使用「狮子印」？\n");
    if((int)me->query("max_force")<3000)
    return notify_fail("你的内力修为太低了!\n");   
    if((int)me->query_skill("jiuzi-zhenyan",1)<160)
    return notify_fail("你的九字真言太差了！\n");
    if((int)me->query_skill("strike",1)<160)
    return notify_fail("你的基本掌法还不到家！\n");
    
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展「狮子印」！\n");
    
    if(me->query_skill("jiuzi-zhenyan",1)>=180)
     flag=1;
    else
     flag=0;
    
        if(flag&&time()-me->query_temp("perform_busy")<10)
       return notify_fail("连续施展「狮子印」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    if(flag&&time()-me->query_temp("perform_busy")<5)
       return notify_fail("连续施展「狮子印」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    damage=me->query("apply_points");
    if(flag) damage=damage*3/2;
    else damage=damage/2;
    
    msg=HIY"$N"+HIY+"一无所惧，长笑一声，倏又往右闪去，同时旋身，长袍转飞，扫往$n"+HIY+"的下盘，左手\n"+
        "拍向$n"+HIY+"的$l，同时右手暗捏狮子印，沉喝一声“咄”！\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,0,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");
    
    if(!me->is_fighting())
    return notify_fail("「狮子印」只能在战斗中使用!\n");
    
    msg=HIC"$N"+HIC+"的真言贯耳而入，登时把弥漫全场的惨烈森杀之气消去。此音有若夜半时从禅院响\n"+
        "起的梵诵钟声，似乎远在天边，又若近在耳旁，感觉玄异无伦，能令人心撼神移，奇\n"+
        "妙至极点。\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,0,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");
    
    if(!me->is_fighting())
    return notify_fail("「狮子印」只能在战斗中使用!\n");
    
    msg=WHT"只见$N"+WHT+"脸容不见半点情绪表情的波动，仿如入静的高僧，宝相庄严，但自有一种说不\n"+
        "出的风流潇洒，合而形成奇特的魅力，极具震慑人心的气度，今$n"+WHT+"生出怪异感觉。\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,0,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");
    
    if(!me->is_fighting())
    return notify_fail("「狮子印」只能在战斗中使用!\n");
    
    msg=HIG"$N"+HIG+"微微一笑，忽然一拳击出。此拳不但予人轻如绵絮的感觉，事实上既带不起半点拳\n"+
        "风，亦没半丝儿劲道。当$n"+HIG+"疑惑时，倏地“蓬”的一声，凝定在半空的拳头冲出凌厉\n"+
        "无匹的劲气狂扬，往$n"+HIG+"直击而去。\n"NOR;
    me->add_temp("apply/damage",damage);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,0,0,2);
    me->add_temp("apply/damage",-damage);
    me->delete_temp("action_msg");
    
    me->set_temp("perform_busy",time());
    
    return 1;   
  
}  
