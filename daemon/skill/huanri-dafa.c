//换日大法。岳山内功。
inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
     return 1;
}


int practice_skill(object me)
{
          return notify_fail("换日大法只能通过学来提高!\n");
}


string query_type()
{
	return "force_skill";
}

string query_base()
{
	return "force";
}

int query_exercise(object me)
{
	int level;
	level=(int)me->query_skill("huanri-dafa",1);
        return (level)/10?level/10:1;
}

int query_respirate(object me)
{
	int level;
	level=(int)me->query_skill("huanri-dafa",1);
	return level/5?level/5:1;

}

string sub_exercise(object me)
{
	int level;
	return HIC"$N"+HIC+"五心向天，运起"+HIW+"换日大法，"+HIC+"瞬间"+HIR+"面色红润，"+HIC+"宛如返老还童一般。\n"NOR;

}

string sub_respirate(object me)
{
	int level;
	return HIC"$N"+HIC+"五心向天，运起"+HIW+"换日大法，"+HIC+"瞬间"+HIR+"面色红润，"+HIC+"宛如返老还童一般。\n"NOR;
       
}
string *query_exert() 
{
	return ({"tuotai","huizhuan"});
}
