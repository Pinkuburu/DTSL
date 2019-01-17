
#include <ansi.h>
#include <condition.h>
#include <job_money.h>

inherit F_CLEAN_UP;

int update_condition(object me, int times)
{
   
   object killer;
   
   if(!me->query_temp("buzhi_jiangjing"))
    return 0;
   
   if(times<=0){
   	tell_object(me,HIB"\n你忽然觉得一阵冷风袭来！\n\n"NOR);
   	killer=new("/d/job/jj/killer");
   	
	killer->set("combat_exp",me->query("combat_exp"));
	if(me->query("combat_exp")<500000)
	set_all_skill(killer,me->query("max_pot")-140);
	else
	set_all_skill(killer,me->query("max_pot")-100);
	copy_hp_item(me,killer,"gin");
	copy_hp_item(me,killer,"kee");
	copy_hp_item(me,killer,"sen");
	killer->set("max_force",me->query("max_force"));
	killer->set("force",me->query("max_force"));
	killer->set_temp("apply/armor",50+random(50));
	
	killer->move(environment(me));
	message_vision(HIR"$N朝$n冷笑道:什么佛法佛经,老子就不信这个,你就把小命留在这里好了!\n"NOR,killer,me);
	killer->kill_ob(me);
        killer->set("target_id",me->query("id"));
       	
   	return 0;}
   	   
      me->apply_condition("jj_job", times - 1);
   if( times < 1 ) return 0;
   return CND_CONTINUE;
}
