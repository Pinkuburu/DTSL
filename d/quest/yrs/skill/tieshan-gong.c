//铁扇功。
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([ "action":"$N手中$w一晃，身体划了个弧线，朝$n的$l处打去！",
    "dodge":30,
    "damage":100,
    "parry":50,
    "damage_type":"砍伤",
  ]),
 ([ "action":"$N将气劲集于$w之上，用力朝$n的$l处打去!",
    "dodge":30,
    "damage":150,
    "parry":1,
    "damage_type":"砍伤",
  ]),
  ([ "action":"$N身行轻轻一晃，扇从左手滑到右手，猛地朝$n的$l处打去！",
    "dodge":30,
    "damage":130,
   "parry":20,
    "damage_type":"震伤",
  ]),
  ([ "action":"$N手中$w一张，封住了$n的进攻，同时$w一翻顺势反击过去！",
    "dodge":30,
    "damage":90,
    "parry":60,
    "damage_type":"砍伤",
  ]),
  
 });   


int valid_learn(object me)
{
     
     return 1;  

}

int practice_skill(object me)
{
  object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
 
 return 1;  


}


mapping query_action(object me, object weapon)
{
   return action[random(sizeof(action))];

}

string *query_perform()
{
	return ({"none"});
}
string query_type()
{
	return "blade";
}
string query_base()
{
	return "blade";
}
mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}
