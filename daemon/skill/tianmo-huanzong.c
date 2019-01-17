//天魔幻踪.

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n身行晃如鬼魅，如幻影一般，坐闪右晃，一招「幻影丛生」躲开了$N的攻击。" 
]),
([      "action" : "$n脚踏玄步，身行忽隐忽现，正是一招「魔影无形」，轻轻地躲开了$N的攻击。"
]),
([      "action" : "$n微微一笑，姿态潇洒之极，一招「魔笑清风」轻轻地躲开了$N的攻势!" 
]),
([      "action" : "$n不慌不忙，身行忽然凌空越起，正是阴癸派的秘籍「天魔渡天」，轻松的躲开了$N的攻击。"
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}


int valid_learn(object me)
{
       if(me->query_skill("dodge",1)<10)
       return notify_fail("你的基本轻功修为不够，无法领略天魔幻踪。\n");

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

string *query_perform()
{
   return ({"modun"});
}

int query_dodge(object me)
{
	return 80;
}