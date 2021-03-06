
//天魔凌霄斩。

/*
此类型 perform 的写法规则：

在 /daemon/skill/相应基本技能/perform名字/ 下建立相应的perform文件。
如：tianmo-zhan 属于 dagger 类，则 perform 文件目录为：
    /daemon/skill/dagger/lingxiao.c
   战斗系统将会根据 perform 的提供的变量来寻找执行文件。
   如 perform lingxiao 的变量为：actionp_hit/lingxiao
   则 战斗系统会 到 /daemon/skill/effskill/ 下寻找lingxiao.c 这个
   文件，并执行文件的 hit_ob(object me,object victim) 函数。
   
   所以添加这样类型的perform，只要保证 变量名字 和 
   /daemon/skill/effskill/ 下的执行文件名字一致就可以了。
*/
/*
变量说明：
flag:用于判断是否击中对方，
     flag=COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),0,1);
     do_attack函数参数：1)me:攻击方，2)victim:防守方
                        3)me->query_temp("weapon"):攻击方的武器
                        4)是否使用了 apply 而使用的 mapping apply_action
                          一般调用，此参数可以为零。
                        5)标志。一般为 1。
     返回值 flag 为 1 时，表示击中，0 为没击中。

ini_damage_apply: 攻击方最初的附加伤害。

执行方式：

1)首先判断 攻击方是否有 apply_effskill_lingxiao 变量 ，如果有，则不执行，
    可以防止陷入死循环中。
2) effskill_lingxiao_times 变量数值加一。

3) 看 effskill_lingxiao_times 是否达到 大于 2，如果是，则继续。

4) 设定 apply_effskill_lingxiao 变量，防止陷入死循环中。步骤 1)需要判断。

5) 看是否可以出三招。

6) 将 effskill_lingxiao_times 变量设为 -1，这样如果要再使用此招数，必须
   过 四 招后才可以。

7) 删掉 apply_effskill_lingxiao 变量，可以继续使用此招数。

*/


inherit SSERVER;

#include <ansi.h>

void show_msg(object me,object victim)
{
    string str;
    
     if (userp(victim))
          if (victim->query("eff_kee")<0 || 
          !living(victim) 
          )
                 {
          str="听说"+victim->name()+""HIM"死在"+me->name()+""HIM"的"HIW"天魔凌宵斩"HIM"之下，尸体上满是锐器留下的伤痕！"NOR;
                        message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
     }
     return;
}

void hit_ob(object me, object victim)
{   
    int flag,ini_damage_apply,damage;
    string str;
         //1)
     if(me->query_temp("apply_effskill_lingxiao",1))
     return;
     //2)
     me->add_temp("effskill_lingxiao_times",1);
    
    if (victim->query("eff_kee")<0 || !living(victim) )  
    return;
    
    if(!me->is_fighting(victim))
    return;
    //3)
    if(me->query_temp("effskill_lingxiao_times")<2)
    return;
    //4)
    me->set_temp("apply_effskill_lingxiao",1);
         
    //5)   
   if ( random(2)>0 ){
   	    //6)
   	    me->set_temp("effskill_lingxiao_times",-1);  
   	    
   	    damage=me->query("apply_points")*3/2+me->query_skill("tianmo-zhan",1)*2/3;//damage 取气势
   	    
   	    if(!me->query("perform_quest/lingxiao"))
   	    damage=damage/2;
   	        	  
            me->add_temp("lingxiao_time",-1);
            
            me->add_temp("apply/damage",damage);
            str=HIG"$N"+HIG+"催动天魔大法，只以赤足的一对拇指触地，白衣飘舞，整个人像没有重量似的，\n"+
               "以无比轻盈和优美的姿态，有如鬼魅般飘拂不定的往$n"+HIG+"攻来。\n"NOR;
            me->set_temp("action_msg",str);//战斗系统将调用此变量描述
            flag=COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),0,1);
            me->add_temp("apply/damage",-damage);
            if(!me->is_fighting()){
             me->delete_temp("apply_effskill_lingxiao");
             me->delete_temp("action_msg");
             show_msg(me,victim);
             return; 
            }    
            
      if(flag){
           me->add_temp("apply/damage",damage);
           str=HIR"$N"+HIR+"一个旋身，欺入$n"+HIR+"怀里，两袖往上掀起，露出赛雪欺霜的小臂，\n"+
               "左右手天魔斩分取$n"+HIR+"的咽喉和小腹，凌厉至极。\n"NOR;
           me->set_temp("action_msg",str);
           flag=COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),0,1);         
           me->add_temp("lingxiao_time",-1);
           me->add_temp("apply/damage",-damage);
           if(!me->is_fighting()){
             me->delete_temp("apply_effskill_lingxiao");
             me->delete_temp("action_msg");
             show_msg(me,victim);
             return; 
            } 
        }
      if(flag){
           me->add_temp("apply/damage",damage);
           str=WHT"$N"+WHT+"深深吸了一口气，从$n"+WHT+"怀里忽地袅袅婷婷的升起，$w遥指$n"+WHT+"，气势逼人，\n"+
               "在上升的途中，再攻出诡异至极的一招！\n"NOR;
           me->set_temp("action_msg",str);
           flag=COMBAT_D->do_attack(me, victim, me->query_temp("weapon"),0,1);         
           me->add_temp("lingxiao_time",-1);
           me->add_temp("apply/damage",-damage);
           me->delete_temp("action_msg");
           
           show_msg(me,victim);
           if(!me->is_fighting()){
             me->delete_temp("apply_effskill_lingxiao");
             me->delete_temp("action_msg");
             return; 
            } 
           

           }  
          
    }             
    else{
     me->add_temp("lingxiao_time",-1);
    }
    //7)    
    me->delete_temp("apply_effskill_lingxiao");
    me->delete_temp("action_msg");
    
          
}
 
