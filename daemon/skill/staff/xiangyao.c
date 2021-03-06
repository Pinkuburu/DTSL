//伏魔杖法
//金刚降妖
//by rzy 02.9.19

#include <ansi.h>
inherit SSERVER;

int perform(object me,object target) {
	object weapon;
	int damage=me->query("apply_points")*5/2;
	string msg;
	int ap,vp;

	weapon=me->query_temp("weapon");

	if(!target)
          if(!objectp(target=offensive_target(me)))
		return notify_fail("目前你没有攻击的目标！\n");
	if(!me->is_fighting())
		return notify_fail("「金刚降妖」要在战斗中使用！\n");
	if(me->query("PKS")>=5)
        return notify_fail("你罪孽深重，无法使用此绝技了！");
	if(!weapon)
		return notify_fail("空手无法使用「金刚降妖」！\n");
	if(weapon->query("skill_type")!="staff")
		return notify_fail("你使用的武器不对！\n");
	if(weapon->query("flag")==1)
		return notify_fail("断掉的兵器不能再使用了！\n");
	if(!me->query_skill("fumo-zhangfa",1))
		return notify_fail("你还没有学会「伏魔杖法」！\n");
	if(me->query("apply_points")<=0)
		return notify_fail("你的气势不足，无法使用「金刚降妖」！\n");
	if((int)me->query("max_force")<1500)
		return notify_fail("以你的内力修为，使不出「金刚降妖」这种绝技！\n");
	if((int)me->query_skill("staff",1)<110)
		return notify_fail("你的基本杖法太差了！\n");
	if((int)me->query_skill("fumo-zhangfa",1)<110)
		return notify_fail("你的「伏魔杖法」还不到家！\n");
	if((int)me->query_skill("wuxiang-shengong",1)<110)
		return notify_fail("你的「无相神功」还不到家！\n");
	if(time()-me->query_temp("perform_busy")<10)
		return notify_fail("连续施展「金刚降妖」需要深厚的先天真气支持，你修为不够，如何能行？\n");
	if(me->query_skill("bikouchan",1)<100)
		return notify_fail("你的闭口禅修为太低了！\n");
	
	ap=me->query_str()+me->query_dex()+me->query("combat_exp")/50000;
        vp=target->query_str()+target->query_dex()+target->query("combat_exp")/50000;

	msg=HIR"$N"+HIR+"突然大喝一声，踏步向前，将全身内力灌注到"+me->query_temp("weapon")->name()+HIR+"上高高举过头顶，\n化巧为拙，硬往$n"+HIR+"头顶砸去！\n"NOR;
		message_vision(msg,me,target);

	if(random(ap+vp/3)>vp) {
		msg = HIW"$n只感到此招数隐隐将自己退路完全封死，毫无躲避之法，眼看$w已向当头砸来！\n"NOR;
		me->add_temp("apply/damage",damage);
		me->set_temp("action_msg",msg);
		COMBAT_D->do_attack(me,target,weapon,0,2);
		me->add_temp("apply/damage",-damage);
		me->delete_temp("action_msg");
		
	}
	else {
		msg = HIY"\n$n只感到此招数隐隐将自己退路完全封死，毫无躲避之法，无奈之下竟运起全身功力硬接了$N此招！\n"NOR;          
		message_vision(msg, me, target);                                        
		me->start_busy(random(4));
		target->start_busy(random(2));                          
		
	}


	me->set_temp("perform_busy",time());
	return 1;

}
