inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N手中$w突然刺出，一招[白蛇出洞]刺向$n的$l！",
    "apply_factor": 5,
    "name" : "招数", 
    "damage_type":"刺伤",
  ]),
 ([ "action":"$N手中$w一横，挡住$n的攻击，$w尾部向前一迎，直撞向$n的$l!",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"震伤",
  ]),
  ([ "action":"$N手中的$w忽然化做万千影子，一招[白鸟朝凤]朝$n刺去！",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N抽身后退，突然身子向后一仰，一招[回马枪]刺向$n的$l！",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"刺伤",
  ])});   




mapping query_action(object me,object weapon)
{
   
return action[random(sizeof(action))];  
 

}



string query_type()    
{                     
	return "spear";
}
string query_base()  
{
	return "spear";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return action[random(sizeof(action))];
	else return action[i-1];
}

