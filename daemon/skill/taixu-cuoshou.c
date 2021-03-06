// 太虚错手。

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N手掌灵活闪动，左掌一晃，右掌猛地朝$n的$l处拍去!",
        "apply_factor": 5,
        "name" : "招数",
       "damage_type": "震伤"
]),

([  "action": "$N身行下沉，右手一格，左手从右手下方斜插过去，猛地打向$n的$l!",
        "apply_factor": 5,
        "name" : "招数",
        "damage_type": "瘀伤"
]),

([      "action": "$N突然贴近$n,双手不住地快攻，如闪电般击向$n的$l！",
        "apply_factor": 5,
        "name" : "招数",
        "damage_type": "瘀伤"
]),

([  "action": "$N左手朝$n的脉门抓去，右手却突然与左手交错而出，打向$n的$l!",
        "apply_factor": 5,
        "name" : "招数",
        "damage_type": "瘀伤"
]),

});


mapping query_action(object me)  
{
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("空了手才能学习太虚错手。\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("必须空手才可以练习[太虚错手]!\n");
     return 1;
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

