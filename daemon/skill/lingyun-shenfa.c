//凌云身法。慈航静斋。

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : HIW"$n身形有如仙子一般，宛如脚踏浮云，潇洒地闪过了$N的进攻。"NOR
]),
([      "action" : HIG"$n身子转了几转，尽数闪开了$N的进攻，动作丝毫不显慌乱，流畅之极。"NOR
]),
([      "action" : HIW"$n步法微妙，身法奇异，宛如腾云一般，高高纵起，轻轻落在$N的身后。!" NOR
]),
([      "action" : HIW"$n面色祥和，看似毫无杂念，只听‘刷’地一声，已然闪在了$N身旁。" NOR
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