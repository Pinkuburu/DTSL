

inherit SSERVER;

#include <ansi.h>


void hit_ob(object me, object victim)
{   
    int flag,ini_damage_apply,damage;
    string str;
         //1)
     if(me->query_temp("apply_effskill_feilong",1))
     return;
     //2)
     me->add_temp("effskill_feilong_times",1);
    
    if (victim->query("eff_kee")<0 || !living(victim) )  
    return;
    
    if(!me->is_fighting(victim))
    return;
    //3)
    if(me->query_temp("effskill_feilong_times")<2)
    return;
    //4)
    me->set_temp("apply_effskill_feilong",1);
         
    //5)   
   if ( random(2)>0 ){
   	    //6)
   	    me->set_temp("effskill_feilong_times",-1);  
   	    
   	    damage=me->query("apply_points")*3/2+me->query_skill("dijian-jue",1)*2/3;//damage 取气势
   	    
   	    if(me->query_skill("dijian-jue",1)<160)
   	     damage=damage/2;
   	      	   
           ini_damage_apply = me->query_temp("apply/damage");
            me->add_temp("feilong_time",-1);
            
            me->add_temp("apply/damage",damage);
            str=HIG"$N"+HIG+"使出飞龙三击第一式，手中$w"+HIG+"散出点点剑光，招数精奇奥妙！\n"NOR;
            me->set_temp("action_msg",str);//战斗系统将调用此变量描述
            flag=COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),0,1);
            if(!me->is_fighting()){
             me->delete_temp("apply_effskill_feilong");
             me->delete_temp("action_msg");
             me->set_temp("apply/damage",ini_damage_apply);
             
             return; 
            }    
            
      if(flag){
           me->add_temp("apply/damage",damage);
           str=HIR"点点剑光散去，凝重的剑气仿佛刺体而入，破空之声刺耳之极，正是飞龙三击第二式！\n"NOR;
           me->set_temp("action_msg",str);
           flag=COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),0,1);         
           me->add_temp("feilong_time",-1);
           me->delete_temp("action_msg");
           if(!me->is_fighting()){
             me->delete_temp("apply_effskill_feilong");
             me->delete_temp("action_msg");
             me->set_temp("apply/damage",ini_damage_apply);
            
             return; 
            } 
        }
      if(flag){
           me->add_temp("apply/damage",damage);
           str=WHT"剑气透体而过，$N"+WHT+"手中$w"+WHT+"化做一道长虹，以难以想象的高速度紧跟而至！\n"NOR;
           me->set_temp("action_msg",str);
           flag=COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),0,1);         
           me->add_temp("feilong_time",-1);
           me->delete_temp("action_msg");
           
           if(!me->is_fighting()){
             me->delete_temp("apply_effskill_feilong");
             me->delete_temp("action_msg");
             me->set_temp("apply/damage",ini_damage_apply);
             return; 
            } 
           

           }  
          
    }             
    else{
     me->add_temp("feilong_time",-1);
    }
    //7)    
    me->delete_temp("apply_effskill_feilong");
    me->delete_temp("action_msg");
    me->set_temp("apply/damage",ini_damage_apply);
          
}
 
