//抓。

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N突然伸出爪子抓向$n\n",
        "dodge": 0,
        "force": 150,
		"damage":50,
        "parry" :50,
        
        "damage_type": "抓伤"
]),
([     "action": "$N突然蹦了过去，挠了$n一下",
       "dodge": 10,
	   "force":10,
	   "parry":10,
	   "damage_type": "抓伤",
]),


});







mapping query_action(object me)
{
        return action[random(sizeof(action))];
}



