#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX 30

int perform(object me, object target)
{
        object weapon;
        string str;
        int i;
        int damage;

        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        || !living(target))
                return notify_fail("搜心断魂只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("tianmo-zhan", 1) < 160 )
                return notify_fail("你的天魔斩功力太浅，别做梦了。\n");

        if( (int)me->query_skill("dagger", 1) < 160 )
                return notify_fail("你的基本匕法功力太浅，别做梦了。\n");
        if( (int)me->query_skill("tianmo-dafa", 1) < 160 )
                return notify_fail("你的天魔大法太浅，别做梦了。\n");
        if(me->query("apply_points")<=0)
                return notify_fail("凭你目前的气势无法施展「搜心断魂」！\n");        
        if( (int)me->query("max_force") < 1800 )
                return notify_fail("你的内力太少，别做梦了。\n");
        if( (int)me->query("force") < 500 )
                return notify_fail("你的真气不够，别做梦了。\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "dagger")
                return notify_fail("你使得了天魔斩绝技么?\n");
        if( time()-me->query_temp("perform_busy")<4)
                return notify_fail("你先天真气不足，无法连续特殊攻击。\n");

        if( me->query_temp("yg_souxin"))
                return notify_fail("你刚使完「搜心断魂」，目前气血翻涌，无法再次运用！\n");

        message_vision(HIR "\n$N突然长啸一声，手中"+weapon->name(me)+HIR+"在半空中划出道道红光，一阵阵天魔气劲向$n"+HIR+"奔袭而去！\n" NOR,me, target);
        me->set_temp("yg_souxin", 2); 

        damage=me->query("apply_points");

        damage=damage/3;
        
        COMBAT_D->do_perform_attack(damage,REDUCE_DEX,"",me,target,weapon,0,2);

        if(me->is_fighting(target)){
        	COMBAT_D->do_perform_attack(damage,REDUCE_DEX,"",me,target,weapon,0,2);
        }
        if(me->is_fighting(target)){
	        COMBAT_D->do_perform_attack(damage,REDUCE_DEX,"",me,target,weapon,0,2);
        }
        me->set_temp("yg_souxin", 1);      
        me->set_temp("perform_busy",time());
        i = (int)me->query_skill("dagger")/25;
        if( 10 - i <= 4) i = 4;
        call_out("remove_effect", i, me);
        
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("yg_souxin");
        tell_object(me, HIR"\n你经过一段时间调气养息，又可以使用「搜心断魂」了。\n"NOR); 
        return;
}
