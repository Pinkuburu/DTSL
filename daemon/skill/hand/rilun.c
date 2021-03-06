//日轮印
#include <ansi.h>

inherit SSERVER;

mapping actionp1=([
		"action":RED"$N"+RED+"暗捏日轮印，手掌心红光闪现，猛地一股热浪朝$n"+RED+"拍去!"NOR,
		"damage":230,
		"parry":100,
		"dodge":40,
		"damage_type":"震伤",
		"skill_name":"jiuzi-zhenyan",
	]);
mapping actionp2=([
		"action":HIR"$N"+HIR+"日轮印不断催动，双掌热浪涌现不断，$n"+HIR+"有些站立不稳了！"NOR,
		"damage":250,
		"parry":100,
		"dodge":50,
		"damage_type":"震伤",
		"skill_name":"jiuzi-zhenyan",
	]);
mapping actionp3=([
		"action":MAG"$N"+MAG+"日轮印劲催之下，四周空气夹带着阵阵热浪，朝$n"+MAG+"拍去！"NOR,
		"damage":300,
		"parry":100,
		"dodge":55,
		"damage_type":"震伤",
		"skill_name":"jiuzi-zhenyan",
	]);

int perform(object me,object target)
{ 
     int lev;
     object weapon;
     weapon=me->query_temp("weapon");	
     if(weapon)
    return notify_fail("拿着武器，如何使用[日轮印]？\n");
    if(!me->is_fighting())
    return notify_fail("只有在战斗时才可以使用日轮印。\n");
    if(!me->query_skill("jiuzi-zhenyan",1))
    return notify_fail("不学[九字真言]如何使用[日轮印]？\n");
    if((int)me->query("max_force")<5000)
    return notify_fail("你的内力修为太低了!\n");
    if((int)me->query("force")<300)
    return notify_fail("你的内力不够使用此招数!\n");
    if((int)me->query_skill("jiuzi-zhenyan",1)<100)
    return notify_fail("你的九字真言太差了！\n");
    if((int)me->query_skill("strike",1)<130)
    return notify_fail("你的[基本掌法]还不到家！\n");
    lev=me->query_skill("jiuzi-zhenyan",1);
    me->set("actionp",actionp1);
    COMBAT_D->do_attack(me,target,0,0,1);
    me->add("force",-100);
    me->delete("actionp");
    
    if(lev<200)
    return 1;
    if(!me->is_fighting())
    return notify_fail("只有在战斗时才可以使用日轮印。\n");
    if((int)me->query("force")<100)
    return notify_fail("你的内力不够使用此招数!\n");
    me->set("actionp",actionp2);
    COMBAT_D->do_attack(me,target,0,0,1);
    me->add("force",-100);
    me->delete("actionp");
    
    if(lev<300)
    return 1;
    if(!me->is_fighting())
    return notify_fail("只有在战斗时才可以使用日轮印。\n");
    if((int)me->query("force")<100)
    return notify_fail("你的内力不够使用此招数!\n");
    me->set("actionp",actionp3);
    COMBAT_D->do_attack(me,target,0,0,1);
    me->add("force",-100);
    me->delete("actionp");
    me->set_temp("perform_busy",time()+5);
    return 1;   
  
}  
