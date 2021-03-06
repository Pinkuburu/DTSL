//抓心掌

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N目光宛如利箭，左掌丝毫不停，朝$n的$l处抓了过去!",
        "dodge": 20,
        "force": 60,
        "parry" : 40,
        "damage_type": "抓伤"
]),

([  "action": "$N运气于左掌，震得$n退后数步，右掌紧跟着朝$n的$l处拍去!",
        "dodge": 30,
        "force": 60,
        "parry" : 40,
        "damage_type": "瘀伤"
]),

([      "action": "$N双掌平推，只见一股巨大的气流朝$n撞去！",
        "dodge": 20,
        "force": 60,
        "parry" : 40,
        "damage_type": "震伤"
]),

([  "action": "$N手掌突然宛如铁钩，猛地朝$n的$l处抓去!",
        "dodge": 30,
        "force": 60,
        "parry" : 40,      
        "damage_type": "抓伤"
]),

});


mapping query_action(object me)  
{
        return action[random(sizeof(action))];
}


string query_type()  
{
	return "hand";
}

string query_base()
{
	return "strike";
}

