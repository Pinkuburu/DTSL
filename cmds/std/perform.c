// perform.c
//written by yanyan. for dt.
//2000.12
inherit F_CLEAN_UP;
#include <skill.h>

int main(object me, string arg)
{
	object target;
	string type,*performs,*skl,perf;
	mapping skills;
	int i,flag;
        int p_damage;
        	
	flag=0;
	seteuid(getuid());

	if( me->is_busy() )
		return notify_fail(" 你上一个动作还没有完成，不能施用外功。\n");
	if(me->query_temp("no_eff_combat"))
	return notify_fail("你现在无法施展外功！\n");
 
    if( !arg ) return notify_fail("你要用外功做什么？\n");
   if ( !wizardp(me)&&environment(me) && environment(me)->query("no_fight")&&!environment(me)->query("leitai")) 
     return notify_fail("这里不能施用外功。\n");

        if( sscanf(arg, "%s on %s", perf, arg)==2 ) {
                target = present(arg, environment(me));
                if( !target ) target = present(arg, me);
                if( !target ) return notify_fail("这里没有 " + arg + "。\n");

 
                if( userp(me) && userp(target) && 
                    target->query_temp("netdead") )
                   return notify_fail("对方正在断线中，不能对其施用外功。\n");
                if(target->query_temp("no_eff_perform"))
                return notify_fail("对方的武功高超，无法向对方施展外功！\n");
               arg=perf+" "+arg;
        } else if(sscanf(arg, "%s %s", perf, arg)==2 ) {
     arg=perf+" "+arg;
        } else perf=arg;
		
    skills=me->query_skills();
	if(!sizeof(skills)) 
		return notify_fail("你没有任何技能!\n");
	skl=keys(skills);
	for(i=0;i<sizeof(skl);i++)
	{
           performs=SKILL_D(skl[i])->query_perform();
	   if(!sizeof(performs)) continue;
	   if(sizeof(performs)>sizeof(performs-({perf})))
	   {
		   flag=1;
		   type=SKILL_D(skl[i])->query_type();
		   break;
	   }
	} 
       if(flag==0)
       return notify_fail("你的外功中没有此技能!\n");
       
       p_damage=me->query_temp("csj_skill_damage");
       if(p_damage&&time()-me->query_temp("csj_damage_time")<p_damage/7){
         tell_object(me,"\n你受了长生诀的伤，内伤加剧了！\n");
         me->receive_wound("kee",p_damage*3);
         return 1;
       }
	  return (int)SKILL_D(type)->perform_action(me,arg);
	  
}

