// 水云袖法。东溟派武功。
//中级-->终极武功。

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N身行左右晃动，手中$w贯注了内力，一招「高山流水」打向$n的$l处！",
        "apply_factor": 2,
        "name" : "高山流水",
        "damage_type": "瘀伤"
]),

([  "action": "$N抽身转式，$w从左右向$n打来，一招「清风双影」打向$n的$l处!",
        "apply_factor": 5,
        "name" : "清风双影",
        "damage_type": "瘀伤"
]),

([      "action": "$N左手挡住了$n的攻击，$w回首一招「清云拂面」扫向$n的$l处！",
        "apply_factor": 10,
        "name" : "清云拂面",
        "damage_type": "瘀伤"
]),

([  "action": "$N身行向前猛地一纵，$w一横，挡住了$n的进攻，随后$w继续攻击，一招「溟水无尽」打了过去！",
        "apply_factor": 7,
        "name" : "溟水无尽",
        "damage_type": "瘀伤"
]),

([  "action": "$N手中$w化为掌式，闪到$n面前，左掌一晃，右手一挥$w，一招「深谷幽云」击向$n!",
        "apply_factor": 8,
        "name" : "深谷幽云",
        "damage_type": "震伤"
]),
});

string *parry_weapon=({

"$N手中的$w宛如灵蛇一般，卷住$n的$v，毫不费力的挡开了$n的进攻。\n",
"$N微微一笑，手中的$w朝$n的手腕卷去，$n一惊，连忙收回了$v。\n",
"$N手中的$w划了一个圆弧，宛如龙游天空，封住了$n的$v。\n",
"$N的$w直朝$n的下盘功去，$n无奈之下，只好收回了$v。\n"

});

string *parry_hand=({

"$N的$w有如长了眼睛，朝$n的手腕卷去，$n无奈之下只好后退几步。\n",
"$N一挥手中的$w，$w宛如铁索一般，横在了两人之间，$n的进攻之力也化为乌有！\n",
"$N轻笑一声，手中的$w挥舞起来，犹如仙子舞蹈，轻轻带过了$n的进攻。\n",
"$N的$w轻轻一带，化解了$n的进攻！\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}


mapping query_action(object me)  
{
        return action[random(sizeof(action))];
        
}

mapping *query_all_action(object me)
{
return action;	
}

int valid_learn(object me)
{
        object weapon;
        
        weapon=me->query_temp("weapon");
        if(!weapon)
         return notify_fail("不拿武器如何学习水云袖法？\n");
        if(weapon->query("skill_type")!="whip")
         return notify_fail("你拿得武器不对。\n");
	
     return 1;  
        
       
}

int practice_skill(object me)
{
      
object weapon;
        
        weapon=me->query_temp("weapon");
        if(!weapon)
         return notify_fail("不拿武器如何练习水云袖法？\n");
        if(weapon->query("skill_type")!="whip")
         return notify_fail("你拿得武器不对。\n");
      
     return 1; 
}

string *query_perform()
{
	return ({"yanyu","youyun"});    
}


string query_type()  
{
	return "whip";
}

string query_base()
{
	return "whip";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/yanyu"))
  return 190;
  return 90;
}

int skill_parry(object me,object victim)
{
  if(me->query("perform_quest/yanyu"))
  return 200;
  return 100;
}