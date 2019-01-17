//鹫鹰天翔

#include <ansi.h>
inherit SKILL;


mapping *action = ({
([      "action" : "$n一声长笑，冲天而起，竟能凌空旋，堪堪避过$N的攻击，往另一个方向投去！"
]),
([      "action" : "$N攻向$n时，$n看似要凌空迎战，岂知竟像蝙蝠般旋避开，予人吻合天地间某一种道\n"+
                   "理的感觉。" 
]),
([      "action" : "$n身躯后仰，险险避开$N的攻击，再斜飞而起，往远处投去，姿态美至极点。" 
]),
([      "action" : "$n好像化成一缕没有重量的轻烟，随呼呼吹来的轻风飘移晃动，每一刻都不断变换位置。"
])

});

mapping query_action(object me)
{
	

	return action[random(sizeof(action))];
}


int valid_learn(object me)
{
       if(me->query_skill("dodge",1)<60)
       return notify_fail("你的基本轻功修为不够，无法领略鹫鹰天翔。\n");

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
   return ({"tianxiang"});
}

int query_dodge(object me)
{
	return 120;
}