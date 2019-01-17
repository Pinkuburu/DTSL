// uptime.c

inherit F_CLEAN_UP;
#include <ansi.h>
// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int main()
{
	int t, d, h, m, s;
	string time;

	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "天";
	else time = "";

	if(h) time += chinese_number(h) + "小时";
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒\n";

	write(GRN "大唐双龙已经运行了" + time + NOR);
       printf(YEL"[ 现在时间 ] "+ CHINESE_D->chinese_newdate( time(), 1 ) +NOR+ "\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : uptime
 
这个指令告诉你游戏已经连续执行了多久.
 
HELP
    );
    return 1;
}
