//百花掌。花间派武功。
//中级。

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N双掌分飞，身形不住地闪动，一招「春花问晓」拍向$n的$l！",
        "apply_factor": 2,
        "name" : "春花问晓",
       "damage_type": "瘀伤"
]),

([  "action": "$N潇洒地一个闪身，左手一抬，宛如护花姿态，右手迅捷地拍向$n,正是一招「夏荷碧影」！",
        "apply_factor": 3,
        "name" : "夏荷碧影",
        "damage_type": "瘀伤"
]),

([      "action": "$N身法突然变慢，双掌护住全身，同时一个转身一招「秋菊迎寒」朝$n拍了过去！",
        "apply_factor": 4,
        "name" : "秋菊迎寒",
        "damage_type": "瘀伤"
]),

([  "action": "$N忽然化做万千身影，双掌隐隐发出阵阵寒气，一招「冷梅飞雪」朝$n的$l处拍去！",
        "apply_factor": 5,
        "name" : "冷梅飞雪",
        "damage_type": "瘀伤"
]),

});

string *parry_weapon=({

"$N手掌上下翻飞，于周身形成一个旋转的气流，$n的$v触到其上滑了开来！\n",
"$N手掌动作轻柔，宛如抚摩鲜花一般，凭借着轻巧之力卸开了$n的$v！\n",
"$N后退一步，左掌虚空一拨，右掌由下至上，正好架住了$n的手腕。\n",
"就在$n的$v攻来之际，$N潇洒地一个错身，如同飘落的花瓣，躲了开来！\n"

});

string *parry_hand=({

"$N手掌向前一伸，如同托着一朵鲜花，猛地手指微动，几个挑拨之间，挡开了$n的进攻！\n",
"$N连忙施展出一招回头望月之势，动作轻柔潇洒，正好架住了$n的进攻！\n",
"$N身形微微一纵，双掌向前横推，手掌张成花瓣形状，封住了$n的攻势。\n",
"$N左掌护住胸口，右掌唰地伸出，如同虬枝突现，$n心中一惊，连忙收势后退！\n"

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
        if((int)me->query_skill("baihua-zhang",1)>400)
            return notify_fail("单纯的学习已经无法让你从本质上提高了，自己去领悟精髓吧。 \n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("空了手才能学习百花掌。\n");
     return 1;  
        
       
}

int practice_skill(object me)
{
      object weapon;
      if(objectp(weapon=me->query_temp("weapon")))
		  return notify_fail("必须空手才可以练习百花掌!\n");
     return 1;
}



string query_type() 
{
	return "hand";
}

string query_base()
{
	return "strike";
}

string *query_perform()
{
  return ({"baihua"});
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
