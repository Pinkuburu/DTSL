//混元气功(force)

inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
      
      return 1;
}


int practice_skill(object me)
{
          return notify_fail("混元气功只能通过学来提高!\n");
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
	return 1;
}

int query_respirate(object me) 
{
	return 1;

}

string sub_exercise(object me)
{
	
	return "$N盘膝坐下，缓缓吐气打坐。\n";
	
}

string sub_respirate(object me)
{
	return "$N盘膝坐下，运气吐故纳新。\n";
}
