//雷霆锤法

//九天轰雷

//by rzy 02.09.24



#include <ansi.h>

inherit SSERVER;



#define REDUCE_DEX 50



int perform(object me,object target) {

	object weapon;

	int damage=me->query("apply_points")*5/2;

	int damage1=random(me->query("apply_points"));

	int ap,vp;

	string msg;



	weapon=me->query_temp("weapon");



	if(!target)

          if(!objectp(target=offensive_target(me)))

		return notify_fail("目前你没有攻击的目标！\n");

	if(!me->is_fighting())

		return notify_fail("「九天轰雷」要在战斗中使用！\n");

	if(!weapon)

		return notify_fail("空手无法使用「九天轰雷」！\n");

	if(weapon->query("flag")==1)

        	return notify_fail("断掉的兵器不能再使用了！\n");

	if(weapon->query("skill_type")!="hammer")

		return notify_fail("你使用的武器不对！\n");

	if(!me->query_skill("leiting-chuifa",1))

		return notify_fail("你还没有学会「雷霆锤法」！\n");

	if(me->query("apply_points")<=0)

		return notify_fail("你的气势不足，无法使用「九天轰雷」！\n");

	if((int)me->query("max_force")<1500)

		return notify_fail("以你的内力修为，使不出「九天轰雷」这种绝技！\n");

	if((int)me->query_skill("hammer",1)<110)

		return notify_fail("你的基本锤法太差了！\n");

	if((int)me->query_skill("leiting-chuifa",1)<110)

		return notify_fail("你的「雷霆锤法」还不到家！\n");

	if((int)me->query_skill("bihai-force",1)<110)

		return notify_fail("你的「碧海神功」还不到家！\n");

	if(time()-me->query_temp("perform_busy")<5)

		return notify_fail("连续施展「九天轰雷」需要深厚的先天真气支持，你修为不够，如何能行？\n");

	if(me->query_skill("dongming-xinfa",1)<100)

		return notify_fail("你的东溟心法修为太低了！\n");



        ap=me->query_str()+me->query_dex()+me->query("combat_exp")/50000;

        vp=target->query_str()+target->query_dex()+target->query("combat_exp")/50000;

        

          msg=HIG"\n$N"+HIG+"忽然横跨一大步，面上红光闪现，手中"+me->query_temp("weapon")->name()+HIG+"化做一道精虹，划出暗合天地至理的一道弧线，充盈的内力使\n"+
			"周围空气压力骤然增大，"+me->query_temp("weapon")->name()+HIG+"尚未及体，真气已压的人喘不过气来！\n"NOR;

		message_vision(msg,me,target);



	if(random(ap+vp)>vp) {

		msg = HIR"$n"+HIR+"只感到此招数浑然天成，避无可避，刹时出了一身冷汗，暗叫：吾命休矣！\n"NOR;

		

		COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,weapon,0,2);

		

	}

	else {

		msg = HIM"$n"+HIM+"只感到此招数浑然天成，难以躲避更无法硬接，当下顾不得身份，倒地便滚，逃开了被一锤砸扁 \n"+

			"的命运，却仍被内力击了一下！\n"NOR;                                                  

		COMBAT_D->do_perform_attack(damage1,REDUCE_DEX,msg,me,target,weapon,0,2);

		me->start_busy(random(1));

		target->start_busy(random(3));

		

	}





	me->set_temp("perform_busy",time());

	return 1;



}



