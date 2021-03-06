// 玲珑玉拳.阴癸派
// 第二等级武功。

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N的姿态优雅，动作毫不慌乱，身行向左一闪，右拳一招「迎门拜客」打向$n的$l!",
        "apply_factor": 2,
        "name" : "迎门拜客",
       "damage_type": "瘀伤"
]),

([  "action": "$N脚踩七星步法，动作有如舞蹈，右拳护住要害，左拳一招「礼尚往来」打向$n的$l!",
        "apply_factor": 5,
        "name" : "礼尚往来",
        "damage_type": "瘀伤"
]),

([      "action": "$N身行猛地腾空而起，如同仙子下凡一般，一招「仙子拂首」击向$n的$l!",
        "apply_factor": 10,
        "name" : "仙子拂首",
        "damage_type": "瘀伤"
]),

([  "action": "$N轻叹一声，左拳划了个圆弧，右拳看似毫不经意地打出，正是一招「有心无心」打向$n的$l!",
        "apply_factor": 7,
        "name" : "有心无心",
        "damage_type": "瘀伤"
]),

});

string *parry_weapon=({

"$N一拳朝$n的$v打去，凭借强大的气劲震开了$n的$v！\n",
"$N姿态优雅，动作毫不慌乱，左拳划了个圆弧，封住了$n的进攻。\n",
"$N身行猛地腾空而起，动作有如舞蹈，躲开了$n的进攻。\n",
"$N轻叹一声，运气于双拳之上，震开了$n的$v！\n"

});

string *parry_hand=({

"$N的双拳迎上$n的进攻，只听碰地一声，双方各退后几步。\n",
"$N拳法诡异，灵蛇一般施展出来，$n见势不好，连忙后退开来！\n",
"$N神情古怪，双拳缓缓递出，正好化解了$n的进攻。\n",
"$N和$n手掌对在一起，只听碰地一声，双方各退后几步。\n"

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
  	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("空了手才能学习玲珑玉拳。\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("必须空手才可以练习[玲珑玉拳]!\n");
     return 1;
}

string *query_perform()
{
	return ({"mie"});   
}


string query_type() 
{
	return "hand";
}

string query_base()
{
	return "cuff";
}

mapping query_select_action(int i)
{
   if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}
int skill_damage(object me,object victim)
{
  
  return 120;
}
