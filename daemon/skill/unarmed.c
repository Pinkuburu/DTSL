//空手招架.

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N伸出手掌拍向$n的$l",
        "apply_factor":2,
        "name":"基本拳脚",
        "damage_type": "瘀伤"
]),
([
 "action":"$N伸出手掌向$n的$l打去!",
 "apply_factor":2,
 "name":"基本拳脚",
 "damage_type": "瘀伤"
]),
([
 "action":"$N蹦了起来,一脚踹向$n的$l!",
 "apply_factor":2,
 "name":"基本拳脚",
 "damage_type": "瘀伤"
])


});





string query_skill_name(int level)
{
        
}

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
	return "base";
}

string perform_action_file(string action)
{
	return __DIR__"hand/"+action;
}

int skill_damage(object me,object victim)
{
	return 20;
}