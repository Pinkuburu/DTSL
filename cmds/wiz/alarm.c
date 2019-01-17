//by 2001/9/29
//by baimo@dtsl
#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg;
	object obj;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);
	if( strlen(msg) > 20 ) return notify_fail("需要这么长吗？\n");
	obj = find_player(target);
	if (!obj) return notify_fail("你要警告谁啊？好象没("+target+")这个人吧。\n");
	CHANNEL_D->do_channel(this_object(),"sys",me->query("id")+"正在发布警告。\n");
	if (wizardp(obj))
		message("system", HIR "【警告】" + me->name(1) +HIR+"("+ me->query("id")
		+ ")「骚扰巫师」的行为造成了不良影响，再犯，严惩。\n" NOR,users());
	else
		message("system", HIR "【警告】" + obj->name(1) +HIR+"("+ obj->query("id")
		+ ")「"+msg+"」的行为造成了不良影响，再犯，严惩。\n" NOR,users());
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：alarm <某人> <讯息>
你可以用这个指令警告一些违反游戏规则的玩家。
HELP
	);
	return 1;
}
