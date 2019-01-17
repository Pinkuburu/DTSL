//内外缚印

#include <ansi.h>



inherit SSERVER;



#define REDUCE_DEX -30



int perform(object me,object target)

{ 

     int flag=0;

     

     object weapon;

     

     if(!target)

    if(!objectp(target=offensive_target(me)))

    return notify_fail("目前你没有攻击的目标！\n");

    

     weapon=me->query_temp("weapon");	

     if(weapon)

    return notify_fail("拿着武器，如何使用「内外缚印」？\n");

    if(!me->is_fighting())

    return notify_fail("只有在战斗时才可以使用「内外缚印」。\n");

    if(!me->query_skill("jiuzi-zhenyan",1))

    return notify_fail("不学「九字真言」如何使用「内外缚印」？\n");

    if((int)me->query("max_force")<3000)

    return notify_fail("你的内力修为太低了!\n");

    if((int)me->query("force")<200)

    return notify_fail("你的内力不够使用此招数!\n");

    if((int)me->query_skill("jiuzi-zhenyan",1)<160)

    return notify_fail("你的九字真言太差了！\n");

    if((int)me->query_skill("strike",1)<160)

    return notify_fail("你的基本掌法还不到家！\n");

    

    if(time()-me->query_temp("perform_busy")<20)

      return notify_fail("连续施展「内外缚印」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    

    me->add("force",-200);

    

    flag+= COMBAT_D->do_perform_attack(0,REDUCE_DEX,"",me,target,0,0,2);

    

    if(!me->is_fighting())

    return notify_fail("「内外缚印」只能在战斗中使用!\n");

    

    flag+=COMBAT_D->do_perform_attack(0,REDUCE_DEX,"",me,target,0,0,2);

    

    if(flag){

       message_vision("\n$n被$N击中，内力不由得狂泻而出！\n",me,target);

       target->add("force",-me->query_skill("jiuzi-zhenyan",1)*2);

       if(target->query("force")<0)

        target->set("force",0);

    }

    

    me->set_temp("perform_busy",time());

    return 1;   

  

}  

