//天一玄功。花间派武功。

inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
     return 1;
}


int practice_skill(object me)
{
          return notify_fail("天一玄功只能通过学来提高!\n");
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
	int level,level2;
	level=0;level2=0;
	level=(int)me->query_skill("tianyi-xuangong",1);
	if(me->query_skill("busi-yin",1)) level2=me->query_skill("busi-yin",1);
    if(level&&level2){
		if((level/2+level2)<50) return 15;
        if((level/2+level2)<120) return 20;
		return 35;}
	else{
		if(level<50) return 15;
		if(level<120) return 20;
		return 25;
	}
}

int query_respirate(object me)
{
	int level,level2;
	level=0;level2=0;
	level=(int)me->query_skill("tianyi-xuangong",1);
	level2=me->query_skill("busi-yin",1);
	if(level&&level2){
		if((level/2+level2)<50) return 20;
        if((level/2+level2)<120) return 25;
		return 35;}
	else{
	if(level<=50)
	return 20;
	else if(level<=120) return 22;
	else return 25;
	}

}

string sub_exercise(object me)
{
	int level;
	level=(int)me->query_skill("tianyi-xuangong",1);
	if(level<=50) return HIG"$N"+HIG+"盘膝而坐，运气打坐，脸上呈现出一片祥和的气象.\n"NOR;
	else if(level<=120) return CYN"$N"+NOR+CYN+"吐息自然，"+HIW+"气走全身，"+NOR+CYN+"似已超然物外.\n"NOR;
	else return HIY"$N"+HIY+"盘膝静坐，气运"+HIR+"丹田，"+HIY+"似与周围万物溶于一体.\n"NOR;
}

string sub_respirate(object me)
{
	int level;
	level=(int)me->query_skill("tianyi-xuangong",1);
	if(level<=50) return HIG"$N"+HIG+"盘膝而坐，运气打坐，脸上呈现出一片祥和的气象.\n"NOR;
	else if(level<=120) return CYN"$N"+NOR+CYN+"吐息自然，"+HIW+"气走全身，"+NOR+CYN+"似已超然物外.\n"NOR;
	else return HIY"$N"+HIY+"盘膝静坐，气运"+HIR+"丹田，"+HIY+"似与周围万物溶于一体.\n"NOR;
}
string *query_exert() 
{
	return ({"yin"});
}


