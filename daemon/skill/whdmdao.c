//五虎断门刀.
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N身行晃动,猛地一招[猛虎下山]砍向$n的$l！",
    "apply_factor": 5,
    "name" : "招数", 
    "damage_type":"砍伤",
  ]),
 ([ "action":"$N身行猛地向前一冲,脚下虚晃一扫,一招[虎啸龙吟]举刀向$n的$l砍去！",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"砍伤",
  ]),
  ([ "action":"$N腾空越起,挥刀凌空砍下,正是一招[猛虎飞天]！",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"砍伤",
  ]),
  ([ "action":"$N大喝一声,一招[猛虎三叠]连环朝$n砍去！",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"砍伤",
  ])});   



int valid_learn(object me)    //被learn调用.
{
 
     return 1;    


}

int practice_skill(object me)  
{
   
 return 1;  


}


mapping query_action(object me,object weapon)
{
   return action[random(sizeof(action))];
 

}


string query_type()    
{                      
	return "blade";
}
string query_base()  
{
	return "blade";
}

