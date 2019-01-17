

#include <ansi.h>

inherit SKILL;

int valid_learn(object me)  
{

        int i = (int)me->query_skill("force", 1);
        if (i>400) return notify_fail("学就只能学的这里了，剩下的要靠你自己领悟了。 \n");
        return 1;
}


string exert_function_file(string func)
{
        return "/daemon/skill/force/" + func;
}

string *query_exert()
{
	return ({"jing","qi","shen","heal"});
}

string query_type()
{
	return "base";
}
