//for 成咬金.三板斧.
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N快步上前，喊了一声[削耳朵],向$n脑袋削去！",
    "apply_factor": 5,
    "name" : "招数",  
    
    "damage_type":"砍伤",
  ]),
 ([ "action":"$N大斧横抡,喊了一声[砍脑袋],砍向$n的头部！",
    "apply_factor": 5,
    "name" : "招数",
   "damage_type":"砍伤",
  ]),
  ([ "action":"$N一楞神,说道:忘了！",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"砍伤",
  ])
  });   


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
	return "axe";
}
string query_base() 
{
	return "axe";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

