// 天魔带
//终极武功。

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N宽袖中左右各飞出一条白色丝带，同时诡异的以右足撑起身躯，整个最毒妇人\n"+
                  "心以奇异曼妙的旋动起来，交叉穿梭织出一个幻变无方，充满气劲的浑圆白球直\n"+
                  "点$n的$l！",
        "apply_factor": 2,
        "name" : "流云无影",
        "damage_type": "瘀伤"
]),

([      "action": "$N以一个浑然天成的娇姿妙态，从两袖中射出$w，像绞缠而有生命的一对灵蛇般，\n"+
                  "遁着迂回曲折的路线，卷向$n！",
        "apply_factor": 5,
        "name" : "天魔飞仙",
        "damage_type": "瘀伤"
]),

([      "action": "$N整条$w在先现出波浪似的曲纹，然後变成十多个旋动的圈环，随着微如影附形\n"+
                  "的凌空去势罩向$n！",
        "apply_factor": 10,
        "name" : "千里飞袖",
        "damage_type": "瘀伤"
]),

([      "action": "$N只以赤足的一对拇指触地，白衣飘舞，整个人像没有重量似的。以无比轻盈和优芙\n"+
              "的姿态，$w拂出其中暗含的指劲杀著往$n攻来。$n四面八方尽是袖影狂风，像一面无\n"+
              "所不被的网。",
        "apply_factor": 7,
        "name" : "天魔扑面",
        "damage_type": "震伤"
]),

([  "action": "$N的$w毒蛇般从罗袖滑出，疾取$n後颈，刚好赶在$n吐气出招一刻击中他，时间拿捏\n"+
              "之妙，即使对方乃索命之敌，$n仍要佩服得五体投地。 ",
        "apply_factor": 8,
        "name" : "天魔分身",
        "damage_type": "瘀伤"
]),
});

string *parry_weapon=({

"$N灌注真力于$w之上，只听兵地一声架住了$n的$v！\n",
"$N一声轻笑，$w卷出一个圆圈，朝$n的$v卷去！\n",
"$N手中的$w如灵蛇一般，正好挡住$n的$v。\n",
"$N纵身越起，$w如长了眼睛一般，正好挡住$n的$v！\n"

});

string *parry_hand=({

"$N手中的$w如同灵蛇一般，卷向$n的手腕，$n连忙退开，惊出一身冷汗！\n",
"$N手中的$w一横，宛如铁索一般挡住了$n的攻击！\n",
"$N一挥手中的$w，一道气劲挡住了$n的攻势。\n",
"$N手中的$w如同灵蛇一般，打向$n的$l，$n连忙退开，惊出一身冷汗！\n"

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
         return notify_fail("不拿武器如何学习天魔带？\n");
        if(weapon->query("skill_type")!="whip")
         return notify_fail("你拿得武器不对。\n");
        
     return 1;  
        
       
}

int practice_skill(object me)
{
      
object weapon;
        
        weapon=me->query_temp("weapon");
        if(!weapon)
         return notify_fail("不拿武器如何练习天魔带？\n");
        if(weapon->query("skill_type")!="whip")
         return notify_fail("你拿得武器不对。\n");
      
     return 1; 
}

string *query_perform()
{
        return ({"yulong","moying"});    
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
	
	return 150;
}