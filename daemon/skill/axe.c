// axe.c

inherit SKILL;

mapping *action=({
([ "action":"$N举起斧头向$n砍去！",
    "dodge":20,
    "damage":10,
    "force":10,
    "damage_type":"砍伤",
]),
([  "action":"$N身行一晃，轮起斧头向$n头部猛的砍去!",
    "dodge":10,
    "damage":15,
	"damage_type":"砍伤",
]),
([
 "action":"$N紧步上前，挺身向$n砍了过去",
 "dodge":10,
 "damage":10,
 "damage_type":"砍伤",
])



});   







mapping query_action(object me,object weapon)
{
	return action[random(sizeof(action))];
}

string query_type()
{
	return "base";
}


string perform_action_file(string action)
{
	return __DIR__"axe/"+action;
}

int valid_learn(object me)  
{

        int i = (int)me->query_skill("axe", 1);
        if (i>400) return notify_fail("学就只能学的这里了，剩下的要靠你自己领悟了。 \n");
        return 1;
}
