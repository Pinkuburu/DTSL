// 八步赶蝉

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n就地一滚，躲开了$N的攻击。" ,
	    "dodge"  : 30
]),
([      "action" : "$n向后一窜，闪开了$N的攻击。" ,
	    "dodge"  : 25
]),

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}



string query_type()
{
	return "dodge";
}

string query_base()
{
	return "dodge";
}