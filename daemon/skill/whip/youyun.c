//水云袖法

//幽云无尽

//by rzy 02.09.24



#include <ansi.h>

inherit SSERVER;



int perform(object me,object target) {

        object weapon;

        int ap,vp;

   

        weapon=me->query_temp("weapon");

        

        if(!target)

          if(!objectp(target=offensive_target(me)))

        	return notify_fail("目前你没有攻击的目标！\n");

        if(!me->is_fighting())

                return notify_fail("只有在战斗时才可以使用「幽云无尽」！\n");

        if(!weapon)

                return notify_fail("空手无法使用「幽云无尽」！\n");

        if(weapon->query("skill_type")!="whip")

		return notify_fail("你使用的武器不对！\n");

	if(weapon->query("flag")==1)

		return notify_fail("断掉的兵器不能再使用了！\n");

        if((int)me->query_skill("bihai-force",1)<110)

        	return notify_fail("你的「碧海神功」修为太低！\n");

        if(!me->query_skill("shuiyun-xiufa",1))

                return notify_fail("你还没有学会「水云袖法」！\n");

        if((int)me->query("max_force")<1000)

                return notify_fail("以你的内力修为无法使出「幽云无尽」这样的招数！\n");

        if((int)me->query_skill("shuiyun-xiufa",1)<110)

                return notify_fail("你的「水云袖法」还不够娴熟！\n");

        if((int)me->query_skill("whip",1)<110)

                return notify_fail("你的基本鞭法还不到家！\n");

	if(me->query("apply_points")<=0)

		return notify_fail("你的气势不足，无法使用「幽云无尽」！\n");

        if(time()-me->query_temp("perform_busy")<4)

                return notify_fail("连续施展「幽云无尽」需要深厚的先天真气支持，你修为不够，如何能行？\n");

        if(me->query_skill("dongming-xinfa",1)<100)

		return notify_fail("你的东溟心法修为太低了！\n");

	

	ap=me->query_str()+me->query_dex()+me->query("combat_exp")/50000;

        vp=target->query_str()+target->query_dex()+target->query("combat_exp")/50000;

        

	message_vision(MAG"不见$N"+MAG+"有什么动作，手中"+weapon->name(me)+MAG+"却忽然向前一圈圈的卷了过来，内劲阴柔不断，仿佛此招连绵不绝，\n没个终了的时候。 \n"NOR,me,target);

		

		

        if(!target->query_temp("weapon")) {

        	

        	if(random(ap+vp)>vp) {

                	message_vision(HIB"\n"+target->name()+HIB+"被$N"+HIB+"的内劲卷了进去，不由自主的跟着转了几个圈！\n"NOR,me,target);

                	target->start_busy(4);         

        	}

        	else {

			message_vision(HIG"\n"+target->name()+HIG+"看出事情不妙，向后疾退，$N"+HIG+"的劲力全部落空了！\n"NOR,me,target);

			me->start_busy(random(2)); 

		}

	}

        if(target->query_temp("weapon")) {

        	

        	if(random(ap+vp)>vp) {

        		message_vision(HIR"\n"+target->name()+HIR+"见此内劲虽是阴柔，却不深厚，当下鼓起内力将其震散，\n却一没留神手中的"+target->query_temp("weapon")->name()+HIR+"被"+weapon->name(me)+HIR+"跟了过来缠了个结实！\n"NOR,me,target);	

			target->start_busy(random(3));

		}

		else {

			message_vision(HIW"\n"+target->name()+HIW+"觉得此招不似看上去一般简单，撤回手中"+target->query_temp("weapon")->name()+HIW+"跃了开去。\n"NOR,me,target);

			me->start_busy(random(2)); 

		}

	}

	me->set_temp("perform_busy",time());

	return 1;

}