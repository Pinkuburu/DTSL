//陶.

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action": "$N右拳猛地打出,一招[狂风暴雨]打向$n的$l!",
        "apply_factor": 5,
        "name" : "招数",
        
        "damage_type": "瘀伤"
]),

([  "action": "$N身行漂浮,双拳如幻影一般,正是一招[如来千手]打向$n!",
        "apply_factor": 5,
        "name" : "招数",
       
        "damage_type": "瘀伤"
]),

([      "action": "$N突然身行下压,双拳猛功向$n的下盘,正是一招[龙行浅底]！",
        "apply_factor": 5,
        "name" : "招数",
      
        "damage_type": "瘀伤"
]),

([  "action": "$N大喝一声,全然不顾防守,一招[鱼死网破]打向$n!",
        "apply_factor": 5,
        "name" : "招数",
        
        "damage_type": "瘀伤"
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
	return "cuff";
}

