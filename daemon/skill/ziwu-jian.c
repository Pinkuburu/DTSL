//子午剑。
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N手中$w走势凌厉，带着一阵寒风，猛地刺向$n的$l！",
    "apply_factor": 2,
    "name" : "招数",  
    "damage_type":"刺伤",
  ]),
 ([ "action":"$N手中$w挽了个剑花，手腕一抖，只见一点寒气朝$n的$l刺来！",
    "apply_factor": 2,
    "name" : "招数",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N身行飞速晃动，手中$w画了个弧线，直朝$n的$l刺去！",
    "apply_factor": 2,
    "name" : "招数",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N低哼一声，手中$w宛如流星一般“唰”地一声刺向$n的$l!",
    "apply_factor": 2,
    "name" : "招数",
    "damage_type":"刺伤",
  ])});   

int valid_learn(object me)  
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
	return "sword";
}
string query_base()  
{
	return "sword";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}
