//落花蝶舞。
//花间派轻功。

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n身形虚晃之间，犹如在花丛中观赏鲜花一般，正是一招「幽然花瘦」轻巧地躲开$N的进攻。"
]),
([      "action" : "$n身体忽然如轻烟一般，宛如凋零的花朵飘然落地一样，躲开了$N的进攻，正是一招「风起花飞」。"
]),
([      "action" : "$n身形步法突然变得快捷起来，犹如蝴蝶在花丛中飞舞，一招「彩蝶轻致」避开了$N的攻击。" 
]),
([      "action" : "虽然$N的攻势不小，但是$n却是不慌不忙，犹如飞舞在花丛中的蝴蝶，一招「蝶舞花丛」轻轻躲了开来。" 
])

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
	return "dodge";
}
string query_base()
{
	return "dodge";
}

int query_dodge(object me)
{
	return 80;
}