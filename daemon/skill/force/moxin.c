//天魔大法
//魔心

#include <ansi.h>
#include <skill.h>
		
int exert(object me, object target)
{
	int i,damage;
	
	if(target!=me)
			return notify_fail("「魔心」不能用来攻击别人！\n");
	if(environment(me)->query("no_fight"))
	return notify_fail("这里不能使用这么有威胁力的内功！\n");
	if(environment(me)->query("sleep_room"))
	return notify_fail("你不要吵醒别人了！\n");
			
	if(me->query_temp("exert_moxin"))
		return notify_fail("你已经使用「魔心」了！\n");
	
	i=me->query_skill("tianmo-dafa",1);
	if(i>=0 && i<160) {
  		damage=0;		
	}
	if(i>=160 && i<260) {
  		damage=i/5;	
	}	
	if(i>=260 && i<340) {
  		damage=i/4;
	
	}	
	if(i>=340 && i<400) {
  		damage=i/4;

	}
	if(i>=400 && i<450) {
  		damage=i/4;

	}
	if(i>=450 && me->query("tianmodafa_quest_allok")) {
  		damage=i/2;

	}
	else
	if(i>=450 && me->query("tianmodafa_quest_ok")) {
  		damage=i/3;

	}
	else{
	 damage=i/4;

	}
	me->add_temp("apply/damage",damage);
	me->set_temp("exert_moxin",1);
	message_vision(HIR"$N"+HIR+"微一吐纳，脸上红光一闪，神色怪异，嘴角露出诡异的笑容。\n"NOR,me);
	call_out("remove_moxin",180,me);
	return 1;
}

void remove_moxin(object me)
{
if(!me) return;
message_vision(RED"$N"+RED+"轻轻吁了口气，收回了「魔心」神功。\n"NOR,me);	
me->delete_temp("exert_moxin");
	
}

