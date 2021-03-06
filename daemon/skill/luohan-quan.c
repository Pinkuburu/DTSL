// 罗汉拳。净念禅院。
// 低等级

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N步法严谨，出招有条不紊，猛地一式「降龙式」打向$n的$l！",
        "apply_factor": 2,
        "name" : "降龙式",
       "damage_type": "瘀伤"
]),

([  "action": "$N双拳虎虎生风，从两侧朝$n的$l处打来，正是一招「伏虎式」！",
        "apply_factor": 3,
        "name" : "伏虎式",
        "damage_type": "瘀伤"
]),

([      "action": "$N身形后退，丝毫不乱，守中带功地朝$n的$l处打去，正是一招「金钟式」！",
        "apply_factor": 4,
        "name" : "金钟式",
        "damage_type": "瘀伤"
]),

([  "action": "$N猛地贴进$n，双拳飞快进攻，突然一招「伏魔式」打向$n的$l处！",
        "apply_factor": 5,
        "name" : "伏魔式",
        "damage_type": "瘀伤"
]),

});

string *parry_weapon=({

"$N凝神注视$n的$v，看准机会，一下打在$v的边缘，震开了$n的$v。\n",
"$N看准时机，双拳一托$n的手腕，化解了$v的进攻。\n",
"$N一侧头，身形朝旁边一闪，一推$v的手腕，避开了$n的进攻。\n",
"$N的掌势轻轻一带，化解了$n的进攻！\n"

});

string *parry_hand=({

"$N的双拳迎上$n的进攻，只听碰地一声，双方各退后几步。\n",
"$N拳法严谨，丝毫不漏破绽，$n见势不好，连忙后退开来！\n",
"$N低喝一声，双拳一抬，架住了$n的进攻。\n",
"$N的掌势轻轻一带，化解了$n的进攻！\n"

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
      
      if(me->query("PKS")>=5)
      return notify_fail("你感到罪孽深重，无法继续学习下去。\n");  
      
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("空了手才能学习罗汉拳。\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(me->query("PKS")>=5)
      return notify_fail("你感到罪孽深重，无法继续练习下去。\n");  
      
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("必须空手才可以练习罗汉拳！\n");
     return 1;
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
  
  return 40;
}