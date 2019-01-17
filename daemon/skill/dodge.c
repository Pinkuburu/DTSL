// dodge

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n一晃，闪开$N的攻击。" ,
	    "dodge"  : 30
]),
([      "action" : "$n一闪，躲了开来。" ,
	    "dodge"  : 25
]),
([      "action" : "$n连忙后退，躲了开来!" ,
	    "dodge"  : 30
]),
([      "action" : "$n慌忙闪开，避开了$N的攻击。" ,
	    "dodge"  : 40
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}


int valid_learn(object me)
{
    
        int i = (int)me->query_skill("dodge", 1);
        if (i>400) return notify_fail("学就只能学的这里了，剩下的要靠你自己领悟了。 \n");
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
	return __DIR__"dodge/"+action;
}
