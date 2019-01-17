// poison.c

#include <condition.h>
#include <ansi.h>

int update_condition(object me,mapping poison)
{
	if(!mapp(poison))
	return 0;
	if(me->query_skill("changsheng-jue",1))
	return 0;	
	if(poison["last"]<=0)
	return 0;
	if(me->query("jiali")<poison["damage"]){
	me->receive_damage(poison["type"],poison["damage"]);
	me->receive_wound(poison["type"],poison["damage"]);
        message_vision(HIB"$N"+HIB+"中的「"+poison["name"]+"」发作了！\n"NOR,me);}
        if((me->query("eff_gin")<=1||
	   me->query("eff_kee")<=1)&&
	   me->query_condition("quest_poison")){
	   tell_object(me,"你毒发身亡了！\n");
           me->set("last_damage_msg","被「"+poison["name"]+"」毒死了。");
	   return 0;}
        poison["last"]--;
        me->apply_condition("quest_poison",poison);
   	return CND_CONTINUE;
}
