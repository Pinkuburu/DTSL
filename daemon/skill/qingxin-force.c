//清心普善诀。慈航静斋内功。 qingxin-force

inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
	if((int)me->query("PKS",1)>=5)
		return notify_fail("你杀的人太多了，无法学习清心普善诀。\n");
	if(((int)me->query_skill("wuwang-jing",1)-(int)me->query_skill("qingxin-force",1))<10)
		return notify_fail("你的无妄经修为不够，无法领略清心普善诀了！\n");
	return 1;
}


int practice_skill(object me)
{
          return notify_fail("清心普善诀只能通过学来提高!\n");
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
	level=(int)me->query_skill("qingxin-force",1);
	
	if(level<10) return 2;
	
	return (me->query_skill("force",1)/10+level/10+
               me->query_skill("wuwang-jing",1)/10)<100?
			(me->query_skill("force",1)/10+level/10+me->query_skill("wuwang-jing",1)/10):
			60;
}

int query_respirate(object me) //吐纳时调用.
{
	int level;
	level=(int)me->query_skill("qingxin-force",1);
	
	if(level<10) return 2;
	
	return (me->query_skill("force",1)/10+level/10+
               me->query_skill("wuwang-jing",1)/10)<100?
				(me->query_skill("force",1)/10+level/10+me->query_skill("wuwang-jing",1)/10):
				60;

}

string sub_exercise(object me)
{
	int level;
	level=(int)me->query_skill("qingxin-force",1);
	if(level<=100) return HIC"$N"+NOR+HIC+"收敛心神，排除心中杂念，逐渐进入忘我之境。\n"NOR;
	else if(level<=150) return HIC"$N"+NOR+HIC+"双掌放于膝上，五心向天，面容一片祥和之气。\n"NOR;
	else if(level<=200) return YEL"$N"+NOR+YEL+"盘膝而坐，心中毫无杂念，吐息自然。\n"NOR;
	else if(level<=250) return HIY"$N"+NOR+HIY+"缓缓坐下，潜运普善真诀周身骨骼“咯、咯”做响。\n"NOR;
	else if(level<=300) return HIG"$N"+NOR+HIG+"双膝盘坐，低吟一声："+HIR+"“普善无我”"+HIG+"顿时内家真气充裕全身。\n"NOR;
	else if(level<=350) return WHT"$N"+NOR+WHT+"轻轻闭上双目，周身似乎被真气所笼罩，超然于万物之外。\n"NOR;
	else if(level<=400) return HIW"$N"+NOR+HIW+"盘膝而坐，面容祥和，似乎如世外仙子一般。\n"NOR;
	else return MAG"$N"+NOR+MAG+"随意坐下，气走六脉，功行全身。逐渐被"+HIB+"一团内家真气"+NOR+MAG+"笼罩着。\n"NOR;
}

string sub_respirate(object me)
{
	int level;
	level=(int)me->query_skill("qingxin-force",1);
	if(level<=100) return HIC"$N"+NOR+HIC+"收敛心神，排除心中杂念，逐渐进入忘我之境。\n"NOR;
	else if(level<=150) return HIC"$N"+NOR+HIC+"双掌放于膝上，五心向天，面容一片祥和之气。\n"NOR;
	else if(level<=200) return YEL"$N"+NOR+YEL+"盘膝而坐，心中毫无杂念，吐息自然。\n"NOR;
	else if(level<=250) return HIY"$N"+NOR+HIY+"缓缓坐下，潜运普善真诀周身骨骼“咯、咯”做响。\n"NOR;
	else if(level<=300) return HIG"$N"+NOR+HIG+"双膝盘坐，低吟一声："+HIR+"“普善无我”"+HIG+"顿时内家真气充裕全身。\n"NOR;
	else if(level<=350) return WHT"$N"+NOR+WHT+"轻轻闭上双目，周身似乎被真气所笼罩，超然于万物之外。\n"NOR;
	else if(level<=400) return HIW"$N"+NOR+HIW+"盘膝而坐，面容祥和，似乎如世外仙子一般。\n"NOR;
	else return MAG"$N"+NOR+MAG+"随意坐下，气走六脉，功行全身。逐渐被"+HIB+"一团内家真气"+NOR+MAG+"笼罩着。\n"NOR;
}

string *query_exert() 
{
	return ({"qingxin"});
}



