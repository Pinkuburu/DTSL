//秦家锏法。
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N猛一挥锏，一招[泰山压顶]砸向$n的头部！",
    "apply_factor": 5,
    "name" : "招数",  
    "damage_type":"砸伤",
  ]),
 ([ "action":"$N身行晃动,轻巧的躲闪开来,同时一招[开天辟地]打向$n的胸口！",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"砸伤",
  ]),
  ([ "action":"$N手中钢锏飞舞起来,向右越开三尺,回首一招[回头望月]拍向$n！",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"砸伤",
  ]),
  ([ "action":"$N向前紧跟几步,钢锏直出,一招[青蛇出洞]打向$n的心窝！",
    "apply_factor": 5,
    "name" : "招数",
    "damage_type":"砸伤",
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
	return "jian";
}
string query_base() 
{
	return "jian";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

