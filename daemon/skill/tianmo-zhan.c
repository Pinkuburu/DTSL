//天魔斩。type : dagger.
//终极武功。
//
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([ "action":"$N身形微微几晃，手中的$w夹带着一阵风雷的呼啸之声一招「风雷斩」朝$n的$l处斩去！",
    "apply_factor": 2,
    "name" : "风雷斩",
    "damage_type":"砍伤",
  ]),
 ([ "action":"$N轻轻一笑，声音宛如银铃，手中的$w突然刺向$n的$l,正是一招「消魂斩」!",
    "apply_factor": 5,
    "name" : "消魂斩",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N双手握住$w，身形宛如一支利箭，一招「飞云斩」朝$n的$l处刺去！",
    "apply_factor": 10,
    "name" : "飞云斩",
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N体内的真气在不断变化，不断游移，突然一招「无形斩」斩向$n的$l!",
    "apply_factor": 7,
    "name" : "无形斩",
    "damage_type":"砍伤",
  ]),
    
 });   

string *parry_weapon=({

"$N身形微微几晃，双手握住$w用力震开了$n的$v！\n",
"$N体内的真气在不断变化，不断游移，只听碰地一声，震开了$n的$v。\n",
"$N轻轻一笑，声音宛如银铃，手中$w一带，化解了$n的进攻。\n",
"$N轻叹一声，运气于$w之上，震开了$n的$v！\n"

});

string *parry_hand=({

"$N脸上诡异的笑容一闪而过，手中$w似是要攻击$n的$l，$n的攻势不由得停住了。\n",
"$N退后几步，手中$w谣指$n的$l，封住了$n的进攻之势。\n",
"$N手中$w一挥，随后闪开，寻找着进攻的机会。\n",
"$N手中$w一横，虽是简单的招式，却封住了$n的全部进攻之力！\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}

int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "dagger")
                return notify_fail("你使用的武器不对。\n"); 
    return 1;  

}

int practice_skill(object me)
{
  object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "dagger")
                return notify_fail("你使用的武器不对。\n");
 
 return 1;  


}


mapping query_action(object me, object weapon)
{
   return action[random(sizeof(action))];

}
mapping *query_all_action(object me)
{
return action;	
}

string *query_perform()
{
	return ({"lingxiao","duanhun"});
}
string query_type()
{
	return "dagger";
}
string query_base()
{
	return "dagger";
}
mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

void hit_ob(object me,object victim)
{
   if(!me->query_temp("actionp_hit/lingxiao"))
   return;
   
   "/daemon/skill/effskill/lingxiao.c"->hit_ob(me,victim);
   return;
}

int skill_damage(object me,object victim)
{
	
	return 180;
	
}