//云雨双修 辟守玄
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N手中$w轻轻一挥，$n只觉得一股强劲的内力朝自己猛地扑来！",
    "dodge":30,  
    "damage":180, 
	"parry":20,  
    "damage_type":"震伤",
  ]),
 ([ "action":"$N手中$w转了几转，封住了$n的攻势，同时$w的尾部朝$n的$l处撞去！",
    "dodge":30,
    "damage":160,
	"parry":40,
    "damage_type":"震伤",
  ]),
  ([ "action":"$N身行盘旋上升，手中$w集注内力，化做剑式，凌空朝$n的$l处刺去！",
    "dodge":30,
    "damage":150,
	"parry":50,
    "damage_type":"刺伤",
  ]),
  ([ "action":"$N身行下沉，不住旋转，$w宛如利剑般朝$n的$l处刺去，卷起阵阵烟尘！",
    "dodge":30,
    "damage":170,
	"parry":30,
    "damage_type":"刺伤",
  ])});   

int valid_learn(object me)  
{
     return 1;    


}

int practice_skill(object me)  
{
 
 return 1;  


}


mapping query_action(object me,object weapon)
{
   
return action[random(sizeof(action))];  
 

}

string *query_perform()
{
	return ({"none"}); 
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
