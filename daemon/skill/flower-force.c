//飞花流水。
//花间派武功

inherit FORCE;

#include <ansi.h>

int valid_learn(object me)
{       
     return 1;
}


int practice_skill(object me)
{
          return notify_fail("飞花流水只能通过学来提高!\n");
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
	level=(int)me->query_skill("flower-force",1);
	if(me->query_skill("busi-yin",1)) level2=me->query_skill("busi-yin",1);
    if(level&&level2){
		if((level/2+level2)<50) return 15;
        if((level/2+level2)<120) return 20;
		return 35;
	}
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
	level=(int)me->query_skill("flower-force",1);
	level2=me->query_skill("busi-yin",1);
	if(level&&level2){
		if((level/2+level2)<50) return 20;
        if((level/2+level2)<120) return 25;
		return 35;
	}
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
	level=(int)me->query_skill("flower-force",1);
	if(level<=100) return BLU"$N"+NOR+BLU+"盘膝而坐，脸上气色阴晴不定。\n"NOR;
	else if(level<=150) return HIB"$N"+NOR+HIB+"面带微笑，双目微闭，似乎丝毫感觉不到世上的任何烦恼。\n"NOR;
	else if(level<=200) return WHT"$N"+NOR+WHT+"神色祥和，笑容浮面，缓缓运气。\n"NOR;
	else if(level<=250) return HIC"$N"+NOR+HIC+"手指呈捻花状，姿态潇洒，充满周身的气息不显丝毫霸气。\n"NOR;
	else if(level<=300) return HIG"$N"+NOR+HIG+"盘膝而坐，双手微微弹动，空气中隐隐可以听到呼啸之声。\n"NOR;
	else if(level<=350) return HIY"$N"+NOR+HIY+"手指呈捻花状，面色祥和，不带一丝表情。\n"NOR;
	else if(level<=400) return MAG"$N"+NOR+MAG+"吐息自然，面色宛如超脱于世俗之外一般。\n"NOR;
	else return HIM"$N"+NOR+HIM+"呼吸之间，"+HIG+"周身的祥和气氛便增加一分，"+HIM+"似乎早已超脱于这个世界。\n"NOR;
}

string sub_respirate(object me)
{
	int level;
	level=(int)me->query_skill("flower-force",1);
	if(level<=100) return BLU"$N"+NOR+BLU+"盘膝而坐，脸上气色阴晴不定。\n"NOR;
	else if(level<=150) return HIB"$N"+NOR+HIB+"面带微笑，双目微闭，似乎丝毫感觉不到世上的任何烦恼。\n"NOR;
	else if(level<=200) return WHT"$N"+NOR+WHT+"神色祥和，笑容浮面，缓缓运气。\n"NOR;
	else if(level<=250) return HIC"$N"+NOR+HIC+"手指呈捻花状，姿态潇洒，充满周身的气息不显丝毫霸气。\n"NOR;
	else if(level<=300) return HIG"$N"+NOR+HIG+"盘膝而坐，双手微微弹动，空气中隐隐可以听到呼啸之声。\n"NOR;
	else if(level<=350) return HIY"$N"+NOR+HIY+"手指呈捻花状，面色祥和，不带一丝表情。\n"NOR;
	else if(level<=400) return MAG"$N"+NOR+MAG+"吐息自然，面色宛如超脱于世俗之外一般。\n"NOR;
	else return HIM"$N"+NOR+HIM+"呼吸之间，"+HIG+"周身的祥和气氛便增加一分，"+HIM+"似乎早已超脱于这个世界。\n"NOR;
}
string *query_exert() 
{
	return ({"feihua","liushui"});
}
