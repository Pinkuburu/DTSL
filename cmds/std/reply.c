// reply.c
// Last modified by Gmm@Jianghu 1999-8-21

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target, mud;
	object obj;

	if( !arg || arg=="" )
		return notify_fail("你要回答什麽？\n");
        if(environment(me)->query("no_tell")&&!wizardp(me))
	  if(stringp(environment(me)->query("no_tell")))
	    return notify_fail(environment(me)->query("no_tell"));
	  else return notify_fail("这里不准讲话！\n");
	if( !stringp(target = me->query_temp("reply")) )
		return notify_fail("刚才没有人和你说过话。\n");

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
		write("网路讯息已送出，可能要稍候才能得到回应。\n");
		return 1;
	}

	obj = find_player(target);
	if( !obj )
		return notify_fail("刚才和你说话的人现在无法听见你，或者已经离开游戏了。\n");
	if(obj->query("env/block_tell"))
	return notify_fail("对方现在不想和别人说话。\n");
	write("你回答" + obj->name(1) + "："+BCYN+HIY + arg + "\n" NOR);
	tell_object(obj, sprintf("%s回答你："+BCYN+HIY+"%s\n"NOR,
		me->name(1), arg ));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：reply <讯息>

你可以用这个指令和刚才用 tell 和你说话的使用者说话。

see also : tell
HELP
	);
	return 1;
}
