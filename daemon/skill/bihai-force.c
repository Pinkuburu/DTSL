//碧海神功。

inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
    if((int)me->query_skill("bihai-force",1)>400)
        return notify_fail("单纯的学习已经无法让你从本质上提高了，自己去领悟精髓吧。 \n");
	return 1;
}


int practice_skill(object me)
{
	return notify_fail("碧海神功只能通过学来提高!\n");
}


string query_type()
{
	return "force_skill";
}

string query_base()
{
	return "force";
}

int query_exercise(object me)//被打坐时调用。
{
	int level;
	if(me->query_skill("tianmo-dafa",1))
		return notify_fail("你只觉得内心无法平静下来，无法打坐下去!\n");
	level=(int)me->query_skill("dongming-xinfa");
	if(level<=50)
		return 10;
	else if(level<=120) return 15;
	else return 20;
}

int query_respirate(object me) //吐纳时调用.
{
	int level;
	if(me->query_skill("tianmo-dafa",1))
		return notify_fail("你只觉得内心无法平静下来，无法继续吐纳下去！\n");
	level=(int)me->query_skill("dongming-xinfa");
	if(level<=50)
		return -10;
	else if(level<=120) return -15;
	else return -20;

}

string sub_exercise(object me)
{
	int level;
	level=(int)me->query_skill("bihai-force",1);
	if(level<=100) return CYN"$N"+NOR+CYN+"驱除心中的各种杂念，使真气缓缓聚集在丹田之中。\n"NOR;
	else if(level<=150) return YEL"$N"+NOR+YEL+"心神具净，内息在浑身百穴不住游走。\n"NOR;
	else if(level<=200) return HIC"$N"+NOR+HIC+"双掌交叠，放于丹田之处，默运碧海神功。\n"NOR;
	else if(level<=250) return MAG"$N"+NOR+MAG+"呼吸一快一慢，脸上气色阴晴交换。\n"NOR;
	else if(level<=300) return HIM"$N"+NOR+HIM+"气息悠长，一呼一息，连绵不绝。\n"NOR;
	else if(level<=350) return HIY"$N"+NOR+HIY+"面色沉寂，几乎不闻呼吸之声，双掌微动，几乎可以听见海啸之声。\n"NOR;
	else if(level<=400) return HIW"$N"+NOR+HIW+"静坐不动，五心向天，隐隐冒出一股寒气。\n"NOR;
	else return HIG"$N"+HIG+"心神合一，内息在"+NOR+MAG+"浑身百穴"+HIG+"四处游走，周身隐有一股寒气。\n"NOR;
}

string sub_respirate(object me)
{
	int level;
	level=(int)me->query_skill("bihai-force",1);
	if(level<=100) return CYN"$N"+NOR+CYN+"驱除心中的各种杂念，使真气缓缓聚集在丹田之中。\n"NOR;
	else if(level<=150) return YEL"$N"+NOR+YEL+"心神具净，内息在浑身百穴不住游走。\n"NOR;
	else if(level<=200) return HIC"$N"+NOR+HIC+"双掌交叠，放于丹田之处，默运碧海神功。\n"NOR;
	else if(level<=250) return MAG"$N"+NOR+MAG+"呼吸一快一慢，脸上气色阴晴交换。\n"NOR;
	else if(level<=300) return HIM"$N"+NOR+HIM+"气息悠长，一呼一息，连绵不绝。\n"NOR;
	else if(level<=350) return HIY"$N"+NOR+HIY+"面色沉寂，几乎不闻呼吸之声，双掌微动，几乎可以听见海啸之声。\n"NOR;
	else if(level<=400) return HIW"$N"+NOR+HIW+"静坐不动，五心向天，隐隐冒出一股寒气。\n"NOR;
	else return HIG"$N"+HIG+"心神合一，内息在"+NOR+MAG+"浑身百穴"+HIG+"四处游走，周身隐有一股寒气。\n"NOR;
}

string *query_exert() 
{
	return ({"shui","huo"});
}



