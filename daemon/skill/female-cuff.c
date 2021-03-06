/*
女性NPC所使用的拳法，如果不想为某个NPC设计独特的武功，
如普通的侠女等，可以使用这个拳法。
*/

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N倩腰一闪，挥起左拳朝$n的$l处打去！",
        "apply_factor": 5,
        "name": "招",
       "damage_type": "瘀伤"
]),

([  "action": "$N身形往后一退，气沉丹田，双拳猛地朝$n的$l处打去！",
        "apply_factor": 5,
        "name": "招",
        "damage_type": "瘀伤"
]),

([      "action": "$N纵身跃起，双腿一扫，接着一个跟斗，右拳猛地朝$n的$l处打来！",
        "apply_factor": 5,
        "name": "招",
        "damage_type": "瘀伤"
]),

([  "action": "$N左拳一格，挡开$n的进攻，同时右拳朝$n的$l处用力打去！",
        "apply_factor": 5,
        "name": "招",
        "damage_type": "瘀伤"
]),

});


mapping query_action(object me)  
{
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
      return 1;  
        
       
}

int practice_skill(object me)
{
     return 1;
}



string query_type() 
{
	return "hand";
}

string query_base()
{
	return "cuff";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

