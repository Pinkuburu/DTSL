//尤鸟倦 兵器：独脚铜人
inherit SKILL;
#include <ansi.h>

mapping *action=({
([ "action":"$N身行诡异地晃动了几下，手中$w画了个圆弧，朝$n的$l处打去!",
    "dodge":30,  
    "damage":180, 
	"parry":20, 
    "damage_type":"砸伤",
  ]),
 ([ "action":"$N身行如游鱼一般，滑过$n，同时手中$w顺势一带，往$n的$l处砸去!",
    "dodge":30,
    "damage":170,
	"parry":30,
    "damage_type":"砸伤",
  ]),
  ([ "action":"$N握住$w的尾部，气运其上，大喝一声，猛地朝$n的$l处砸去!",
    "dodge":30,
    "damage":160,
	"parry":40,
    "damage_type":"砸伤",
  ]),
  ([ "action":"$N腾身而起，凌空翻转了一个筋斗，挥舞着$w朝$n的$l处用力砸去!",
    "dodge":33,
    "damage":190,
	"parry":10,
    "damage_type":"砸伤",
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


string query_type()    
{                      
	return "staff";
}
string query_base()  
{
	return "staff";
}

mapping query_select_action(int i) 
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

string *query_perform()
{
	return ({"none"});
}

