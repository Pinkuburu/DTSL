//抵天三诀。

#include <ansi.h>

inherit SSERVER;


int perform(object me,object target)
{ 
    object weapon,*ob,team_ob=0;
    string msg;
    int parry,flag,i;
    
    flag=0;
   if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
   if(!me->is_fighting())
	   return notify_fail("「抵天三诀」只能在战斗中使用!\n");
    weapon=me->query_temp("weapon");
    if(!weapon||weapon->query("skill_type")!="sword")
    return notify_fail("手中无剑，如何使用「抵天三诀」？\n");
    if(weapon->query("flag")==1)
		return notify_fail("断掉的兵刃如何使用？\n");
    if(!me->query_skill("dijian-jue"))
    return notify_fail("不学「地剑诀」如何使用「抵天三诀」？\n");
    if((int)me->query("max_force",1)<1000)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("sword",1)<110)
    return notify_fail("你的基本剑法太差了！\n");
    if((int)me->query_skill("dijian-jue",1)<110)
    return notify_fail("你的「地剑诀」还不到家！\n");
    if((int)me->query_skill("tiangang-sanjue",1)<100)
    return notify_fail("你的「天罡三诀」还不到家！\n");
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展「抵天三诀」！\n");
    
    if(me->query("perform_quest/ditian")
      &&time()-me->query_temp("perform_busy")<10)
       return notify_fail("连续施展「抵天三决」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    if(!me->query("perform_quest/ditian")
      &&time()-me->query_temp("perform_busy")<5)
       return notify_fail("连续施展「抵天三决」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    if(me->query_temp("perform_action/ditian"))
    return notify_fail("你正在使用「抵天三诀」。\n");
    
    parry=me->query("apply_points");
    
    if(!me->query("perform_quest/ditian")){
     flag=0;
     parry=parry/2;
    } else flag=1;   
    
    if(!flag){
    	msg=WHT"\n“嗡……”有如古琴拨调，$N"+WHT+"横过手中"+weapon->name()+WHT+"，连剑带鞘，横放於胸，$n"+WHT+"\n"+
    	   "的攻势，如激流般涌向剑刃，但$N"+WHT+"全凭一口先天真气，牢牢守住，整个身子犹如一尊石像，\n"+
    	   "动也不动。\n"NOR;
    	message_vision(msg,me,target);
    	me->set_temp("apply/parry",parry);
    }
    else{
      ob=me->query_team();
      if(!arrayp(ob)){
      	msg=WHT"\n“嗡……”有如古琴拨调，$N"+WHT+"横过手中"+weapon->name()+WHT+"，连剑带鞘，横放於胸，$n"+WHT+"\n"+
    	   "的攻势，如激流般涌向剑刃，但$N"+WHT+"全凭一口先天真气，牢牢守住，整个身子犹如一尊石像，\n"+
    	   "动也不动。\n"NOR;
    	me->set_temp("apply/parry",parry);
      }
      else{
        i=sizeof(ob);
        while(i--)
        if(ob[i])
        ob[i]->set_temp("apply/parry",parry);
        team_ob=ob[random(sizeof(ob))];
        msg=WHT"只听一阵龙吟之声顿起，$N"+WHT+"的"+weapon->name()+WHT+"挥舞起来，宛如点点繁星四方飞散开来，\n"+
            "好似织成了一个大网，将自己周围团团围住，顿时令$n"+WHT+"有无从下手之感！\n"NOR;
      }
      message_vision(msg,me,target);
   }      
   
   me->set_temp("perform_action/ditian",1);
   if(!flag)
   call_out("clear_defence",5,me,ob,flag);
   else
   call_out("clear_defence",10,me,ob,flag);
    
    msg=HIC"$N"+HIC+"的$w"+HIC+"承受$n"+HIC+"大力一击，整柄剑剧烈弯曲，却分毫未损，轻轻摇动，将所有攻击全给抵住，\n"+
        "而且随着$n"+HIC+"的气机震荡，$w"+HIC+"产生了波浪般的抖动，每抖动一次，$w"+HIC+"便直了一分，\n"+
        "将$n"+HIC+"的数重刚劲逐步化去。\n"NOR;
    if(!userp(target))
    me->add_temp("apply/damage",parry);
    me->set_temp("action_msg",msg);
    COMBAT_D->do_attack(me,target,weapon,0,2);
    if(target&&!userp(target))
    me->add_temp("apply/damage",-parry);
    me->delete_temp("action_msg");
  
    if(!me->is_fighting())
    return notify_fail("「抵天三诀」只能在战斗中使用!\n");
    
    msg=YEL"$N"+YEL+"和$n"+YEL+"正自僵持，$n"+YEL+"陡觉手上劲力如泥牛入海，摸不着底处，$N"+YEL+"的攻势如万里长空，\n"+
        "旷远不知其深，包容万物，$w"+YEL+"上突然生出一股的大力，化作三道先天劲气直击$n"+YEL+"。\n"NOR;
    if(!userp(target))
    me->add_temp("apply/damage",parry);
    me->set_temp("action_msg",msg);
    flag=COMBAT_D->do_attack(me,target,weapon,0,2);
    if(target&&!userp(target))
    me->add_temp("apply/damage",-parry);
    me->delete_temp("action_msg");
   
   me->set_temp("perform_busy",time());
    return 1;   
  
}  

void clear_defence(object me,object *ob,int parry,int flag)
{
   string msg;
   int i;  
   
   if(!flag){
     if(!me) return;
     me->set_temp("apply/parry",0);
     
   }
   else{
     if(arrayp(ob)){
     	i=sizeof(ob);
     	while(i--)
     	 if(ob[i])
     	  ob[i]->set_temp("apply/parry",0);
     }
     else{
      if(!me) return;
      me->set_temp("apply/parry",0);
     }
  }
  msg="\n$N收回了地剑诀的防守之势！\n";
  if(me){
   me->delete_temp("perform_action/ditian");
   message_vision(msg,me);
  }
  return;
}
