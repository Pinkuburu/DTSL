// poison.c

#include <condition.h>
#include <ansi.h>
#include <medicine.h>

int update_condition(object me, mapping info)
{
	
	if( !mapp(info) ) return 0;
	
	if(!me->query_temp("medicine_add_temp_parry")) return 0;
	
	if( info["times"] <=0 ){
	  me->add_temp("apply/parry",-info["number"]);
	  tell_object(me,HIY"\n你服用的增加防御的药力效应结束了！\n"NOR);
	  return 0;
        }
        
	info["times"] --;

	me->apply_condition("add_temp_parry", info);
	
	return CND_CONTINUE;
}
