//霓裳飘溟。东溟派武功。

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n身行向旁边一闪，如幻影一般，一招「蜃楼幻出」躲开了$N的进攻。"
]),
([      "action" : "$n身行向上一纵，如清烟一般，一招「乘风羽翮」潇洒地闪到了$N的身后。"
]),
([      "action" : "$n脚踏玄步，几个闪晃，令$N琢磨不定，一招「白云遥首」闪到了$N的身边。"
]),
([      "action" : "$n身行几个闪晃，尽数闪开了$N的进攻，一招「云归碧海」反闪到了$N的身后。"
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