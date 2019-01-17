//天心莲环.
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N双掌并齐，灌注内力，如排山倒海般朝$n压去！",
    "apply_factor": 5,
    "name" : "招数",  
    "damage_type":"震伤",
  ]),
 ([ "action":"$N左手一横，右手手指拇指、中指重叠，只听“波”地一声一股内力弹向$n!",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"震伤",
  ]),
  ([ "action":"$N双手相托，呈现莲花形状，一股内力朝$n猛地压去！",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"震伤",
  ]),
  ([ "action":"$N莲花手形突然一分为二，变化诡异，朝$n的上下两路抓去！",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"抓伤",
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
	return "hand";
}
string query_base()  
{
	return "strike";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
  
  return 100;
}
