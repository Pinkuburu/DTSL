//炎阳大法
//炎阳
//modefied by subzero 02/09/21

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill,lvl;

	if ((int)me->query_skill("yanyang-dafa", 1) < 160)
		return notify_fail("你的炎阳大法修为不够，还不能增强自己的攻击力。\n");
	if((int)me->query("max_force")<1500)
		return notify_fail("你的内力修为太差，多多打坐吧。\n");
	if( (int)me->query("force") < 500 ) 
		return notify_fail("你的真气不够。\n");
	if (me->query_temp("xs/yanyang"))
		return notify_fail("你已经在运真气增加攻击力。\n"); 

	skill = me->query_skill("yanyang-dafa",1)/4;
	lvl = me->query_skill("yanyang-dafa",1)/20;
          if(wizardp(me)) tell_object(me,sprintf("add damage: %d\n",skill));

	message_vision(HIR"\n$N潜运炎阳大法遍部全身，面色如炎阳烈日一般的红晕！\n" NOR, me);

        me->add_temp("apply/damage", skill);
	me->set_temp("xs/yanyang", 1);
        me->add("force", -300);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}
void remove_effect(object me, int amount)
{
	if(!me)
	 return;
	 
	if ( (int)me->query_temp("xs/yanyang") ) {
                me->add_temp("apply/damage", -amount);
		me->delete_temp("xs/yanyang");
		message_vision(RED"$N"+RED+"脸上红光敛去，一切又恢复如常。\n" NOR, me);
	}
}
