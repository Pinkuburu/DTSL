//天魔幻踪。
//魔遁。

#ifndef GO_CMD
#define GO_CMD "/cmds/std/go.c"
#endif
         

#include <ansi.h>
#include <skill.h>
inherit SSERVER;

int perform(object me,object target)
{
        string msg,*doors,way;
        mapping exits;
        int ap,vp;
  		
	if(!objectp(target=offensive_target(me)))
	 return notify_fail("你没有和别人交手，没必要使用「天魔遁」！\n");
	 
	if(!me->is_fighting())
	return notify_fail("「天魔遁」只能在战斗中使用！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if(!me->query_skill("tianmo-huanzong",1))
		return notify_fail("不学天魔幻踪如何使用「天魔遁」？\n");
	if((int)me->query_skill("tianmo-huanzong",1)<100)
		return notify_fail("你的天魔幻踪修为不够！\n");
	if((int)me->query_skill("dodge",1)<100)
		return notify_fail("你的基本轻功修为不够！\n");
	if(me->query("apply_points")<=0)
	return notify_fail("你的气势不足以使用「天魔遁」！\n");
	
	if(time()-me->query_temp("perform_busy")<3)
      return notify_fail("连续施展「天魔遁」需要深厚的先天真气支持，你修为不够，如何能行？\n");

        exits=environment(me)->query("exits");
        if(sizeof(exits)<=0)
        return notify_fail("这里没有出口，你无法使用「天魔遁」！\n");
        
        msg=HIG"\n$N"+HIG+"冷笑一声，身形左右晃动，正是阴癸的秘招「天魔遁」！\n"NOR;
        message_vision(msg,me);
        
        ap=target->query_dex();
        vp=me->query_dex()+me->query_skill("tianmo-huanzong",1)/5;
        
        if(random(ap+vp)>vp){
         msg=YEL"\n$n"+YEL+"反应奇快，身形一闪，拦住了$N"+YEL+"的去路！\n"NOR;
         message_vision(msg,me,target);
        }
        else{
         msg=HIY"\n$N"+HIY+"身形散去，$N"+HIY+"已经无影无踪，只剩下懊恼的$n"+HIY+"。\n"NOR;
         message_vision(msg,me,target);
         
         GO_CMD->do_flee(me);
         me->set("force",0);
         me->set("apply_points",0);
        }
         
        
        me->set_temp("perform_busy",time());
        return 1;
}

