//玉石俱焚
//天魔大法。
/*
使用 玉石俱焚后，如果在三招内击中二招，
则双方共同死亡，否则，只能自己死亡了。
*/

#include <ansi.h>

inherit SSERVER;

int exert(object me,object target)
{ 
    object weapon;
    string msg;
    int flag,lev;
    
    flag=0;
    
   if(!me->is_fighting())
		return notify_fail("「玉石俱焚」只能在战斗中使用!\n");
   if(target==me)
   return notify_fail("「玉石俱焚」只能对别人使用。\n");   
    if(!me->query_skill("tianmo-dafa",1))
    return notify_fail("不学「天魔大法」如何使用「玉石俱焚」？\n");
    
    if((int)me->query("max_force")<1000)
    return notify_fail("你的内力修为太低了！\n");
    
       if((int)me->query("force")<300)
    return notify_fail("你的内力不够使用此招数!\n");
    
    if(me->query_skill("tianmo-dafa",1)<400)
    return notify_fail("你的「天魔大法」修为不够，无法使用如此危险的绝技！\n");
    msg=HIC"$N"+HIC+"低哼一声，周身逐渐发出强劲的天魔气场，朝$n"+HIC+"卷去！\n"NOR;
    
    message_vision(msg,me,target);
      
    lev=me->query_skill("tianmo-dafa",1)/2+me->query_skill("tianmo-dai",1)/2;
    
    me->add_temp("apply/dodge",lev);//因为属于拼命，必然是低手杀高手，
    me->add_temp("apply/damage",lev);//所以这里的攻击和伤害都附加。
    
    me->add("force",-100);    
    flag=COMBAT_D->do_attack(me,target,weapon,0,1);
    me->add_temp("apply/dodge",-lev);
    me->add_temp("apply/damage",-lev);
    
    if(!me->is_fighting())
     return notify_fail("你一招中敌，于是缓缓撤去了周身的气场。\n");
   
   if((int)me->query("force")<100)
    return notify_fail("你的内力不够使用此招数!\n");
    
    msg=HIY"\n$N"+YEL+"不住催动天魔大法，四周的气场逐渐缩小，$N"+YEL+"顺势朝$n"+YEL+"发动攻击！\n"NOR;
    message_vision(msg,me,target);
    
    me->add_temp("apply/dodge",lev);
    me->add_temp("apply/damage",lev);
    
    me->add("force",-100);    
    flag +=COMBAT_D->do_attack(me,target,weapon,0,1);
    me->add_temp("apply/dodge",-lev);
    me->add_temp("apply/damage",-lev);
    
    if(!me->is_fighting())
     return notify_fail("你两招中敌，于是缓缓撤去了周身的气场。\n");
      
   if((int)me->query("force")<100)
    return notify_fail("你的内力不够使用此招数!\n");
    
    msg=HIR"\n$N"+HIR+"最后一催动天魔气场，只见一股强大的天魔气劲朝$n"+HIR+"卷去，$N"+HIR+"同时发出致命一击！\n"NOR;
    message_vision(msg,me,target);
    
    me->add_temp("apply/dodge",lev);
    me->add_temp("apply/damage",lev);
    
    me->add("force",-100);    
    flag +=COMBAT_D->do_attack(me,target,weapon,0,1);
    me->add_temp("apply/dodge",-lev);
    me->add_temp("apply/damage",-lev);
    
    if(flag>=2){//三招中两招，则玉石俱焚！
    
    msg=HIR"只见气场的威力集中于中心一点，瞬间爆发开来，将$N"+HIR+"和$n"+HIR+"炸成了血浆！\n"NOR;
    msg +=RED"\n只见一片血雨腥风朝四周飞散开来！\n"NOR;
    message_vision(msg,me,target);
    
    me->remove_all_killer();
    target->remove_all_killer();
    
    me->set_temp("last_damage_msg",me->name()+"使用「玉石俱焚」和"+target->name()+"同归于尽了。");
    target->set("last_damage_msg","被"+me->name()+"的「玉石俱焚」杀害了。");
    me->delete_temp("last_damage_from");
    me->die();
    me->delete_temp("last_damage_msg");
    me->set("last_damage_msg","使用「玉石俱焚」和"+target->name()+"同归于尽了。");
    target->die();
   
    }
    else{//如果没成功：
    msg=HIR"只见气场的威力集中于中心一点，瞬间爆发开来，$n"+HIR+"拼尽最后力气，从气场中挣脱了出来！\n"NOR;
    msg +=RED"\n只听“膨”地一声，$N"+RED+"被炸成了阵阵血浆，朝四周飞散开来！\n"NOR;
    message_vision(msg,me,target);
    me->remove_all_killer();    
    me->set_temp("last_damage_msg",me->name()+"使用「玉石俱焚」身亡了！\n");
    me->delete_temp("last_damage_from");
    me->die();
    me->delete_temp("last_damage_msg");
    me->set("last_damage_msg","使用「玉石俱焚」身亡了。");
    }
   
    return 1;   
  
}  
 