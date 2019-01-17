//无相神功。净念禅院

inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
	if ((int)me->query_skill("wuxiang-shengong",1)>400) 
    	return notify_fail("学就只能学的这里了，剩下的要靠你自己领悟了。 \n");
	if((int)me->query("PKS",1)>=5)
		return notify_fail("你感到罪孽深重，无法学习此内功。\n");
	if(((int)me->query_skill("chanzong-fofa",1)-(int)me->query_skill("wuxiang-shengong",1))<=10)
        return notify_fail("你忽然觉得自己心中生起好斗的心情，看来有必要修习禅宗佛法了！\n");
	return 1;
}


int practice_skill(object me)
{
          return notify_fail("无相神功只能通过学来提高!\n");
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
	int level,level2;
	level=0;level2=0;
	
	if(me->query_skill("tianmo-dafa",1))
		return notify_fail("你只觉得身体中有股邪气在曼延,不能在继续打坐下去!\n");
	level=(int)me->query_skill("wuxiang-shengong",1);
	if(me->query_skill("changsheng-jue",1)) 
		level2=me->query_skill("changsheng-jue",1);
    if(level&&level2){
		if((level/2+level2)<50) return 20;
        if((level/2+level2)<120) return 30;
		return 45;
	}
	else{
		if(level<50) return 15;
		if(level<120) return 20;
		return 25;
	}
}

int query_respirate(object me) //吐纳时调用.
{
	int level,level2;
	level=0;level2=0;
	
	if(me->query_skill("tianmo-dafa",1))
		return notify_fail("你只觉得身体中有股邪气在曼延,不能在继续吐纳下去!\n");
	level=(int)me->query_skill("wuxiang-shengong",1);
	level2=me->query_skill("changsheng-jue",1);
	if(level&&level2){
		if((level/2+level2)<50) return 0;
        if((level/2+level2)<120) return 10;
		return 15;
	}
	else{
		if(level<=50)
			return -10;
		else if(level<=120) return -15;
		else return -20;
	}

}

string sub_exercise(object me)
{
	int level;
	level=(int)me->query_skill("wuxiang-shengong",1);
	if(level<=100) return CYN"$N"+NOR+CYN+"缓缓运起无相神功，慢慢地在丹田积聚起内力来。\n"NOR;
	else if(level<=150) return HIC"$N"+NOR+HIC+"运气数息，只觉得气走身体各处，说不出的舒服。\n"NOR;
	else if(level<=200) return MAG"$N"+NOR+MAG+"抉弃杂念盘膝坐定，手捏气诀，"+HIB+"渐入无我境界，"+NOR+MAG+"一道炽热的内息在任督二脉之间游走。\n"NOR;
	else if(level<=250) return YEL"$N"+NOR+YEL+"随意坐下，闭口不语，周身被一团"+HIC+"佛家正气"+NOR+YEL+"笼罩着。\n"NOR;
	else if(level<=300) return WHT"$N"+NOR+WHT+"闭口不语，面无表情，好象一尊石像一般。\n"NOR;
	else if(level<=350) return HIW"$N"+NOR+HIW+"静坐如钟，周身透出一股庄严的气息。\n"NOR;
	else if(level<=400) return HIG"$N"+NOR+HIG+"熟练地使气息游走四肢百穴，只觉得内力又更深了一层。\n"NOR;
	else return HIY"$N"+NOR+HIY+"面色慈祥，真气充满周身，似乎包围了一层金色的光芒。\n"NOR;
}

string sub_respirate(object me)
{
	int level;
	level=(int)me->query_skill("wuxiang-shengong",1);
	if(level<=100) return CYN"$N"+NOR+CYN+"缓缓运起无相神功，慢慢地在丹田积聚起内力来。\n"NOR;
	else if(level<=150) return HIC"$N"+NOR+HIC+"运气数息，只觉得气走身体各处，说不出的舒服。\n"NOR;
	else if(level<=200) return MAG"$N"+NOR+MAG+"抉弃杂念盘膝坐定，手捏气诀，"+HIB+"渐入无我境界，"+NOR+MAG+"一道炽热的内息在任督二脉之间游走。\n"NOR;
	else if(level<=250) return YEL"$N"+NOR+YEL+"随意坐下，闭口不语，周身被一团"+HIC+"佛家正气"+NOR+YEL+"笼罩着。\n"NOR;
	else if(level<=300) return WHT"$N"+NOR+WHT+"闭口不语，面无表情，好象一尊石像一般。\n"NOR;
	else if(level<=350) return HIW"$N"+NOR+HIW+"静坐如钟，周身透出一股庄严的气息。\n"NOR;
	else if(level<=400) return HIG"$N"+NOR+HIG+"熟练地使气息游走四肢百穴，只觉得内力又更深了一层。\n"NOR;
	else return HIY"$N"+NOR+HIY+"面色慈祥，真气充满周身，似乎包围了一层金色的光芒。\n"NOR;
}

string *query_exert() 
{
	return ({"roar","jinzhong"});
}


