#include <ansi.h>
inherit SSERVER;

void check(object me);
void remove_effect(object me);

int perform(object me,object victim)
{
        int skill;
        int base_skill,sword_skill;
        
        skill = me->query_skill("tiangang-sanjue",1);
        
        if(skill>200) skill=200;
        
        base_skill= me->query_skill("sword",1);
        sword_skill= me->query_skill("dijian-jue",1);
                       
        if(me->query("apply_points")<=0)
        return notify_fail("凭你目前的气势无法施展「飞龙三击」!\n");
        if(me->query("max_force")<1000)
        return notify_fail("你的内力修为太低了！\n");              
        if( skill < 110 )  return notify_fail("你的天罡三诀修为不够。\n");
        if( base_skill < 110 )  return notify_fail("你的基本剑法未够纯熟。\n");
        if( sword_skill < 110 )  return notify_fail("你的地剑诀未够纯熟。\n");
                
        if( me->query_temp("actionp_hit/feilong") ) 
          {remove_effect(me);return 1;}
                          
        if( time()-(int)me->query_temp("perform_busy") < 6 )
                return notify_fail("你现在真气不纯！\n");  
        
        message_vision(HIY"$N"+HIY+"加快身形，施展开飞龙三击。\n" NOR, me);
        me->set_temp("actionp_hit/feilong", 1);
        me->set_temp("feilong_time",skill/3);
                   
        call_out("check", 1, me);
        return 1;
}


void check(object me)
{       
        object weapon;
         if(!me)//如果没有物件 me，例如me quit了，则返回，不做任何事
        return;
       
        weapon=me->query_temp("weapon");
        if ( !weapon||weapon->query("skill_type") != "sword" ) 
                 remove_effect(me);
         else if(me->query_temp("feilong_time")<10)
             remove_effect(me);                 
         else {  me->add_temp("feilong_time",-1);
                call_out("check", 1, me);
              }
                     
}


void remove_effect(object me)
{
        if(!me) return;//如果没有物件 me，例如me quit了，则返回，不做任何事
        if(!me->query_temp("actionp_hit/feilong"))
        return;
        me->delete_temp("actionp_hit/feilong");
        me->set_temp("perform_busy",time());
        tell_object(me, HIG"\n你收回了地剑诀。\n\n"NOR);
        return;
}
