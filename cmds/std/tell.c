// tell.c
// Last modified by Gmm@Jianghu 1999-8-21

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;
int help(object me);
void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;
	string name, refuse_name;
	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);
	if(environment(me)->query("no_tell")&&!wizardp(me))
	  if(stringp(environment(me)->query("no_tell")))
	    return notify_fail(environment(me)->query("no_tell"));
	  else return notify_fail("这里不准讲话！\n");
	if( sscanf(target, "%s@%s", target, mud)==2 )
	{
		GTELL->send_gtell(mud, target, me, msg);
		write("网路讯息已送出，可能要稍候才能得到回应。\n");
		return 1;
	}
	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("没有这个人....。\n");
	if(obj->query("env/block_tell"))
	return notify_fail("对方现在不想和别人说话。\n");
	name = (string) me->query("id");
	refuse_name = (string) obj->query("env/no_tell");
	if( refuse_name == "all" || refuse_name == name)
	return notify_fail("此人已关闭了ＴＥＬＬ频道。\n");
	write("你告诉" + obj->name(1) + "："+BCYN+HIY + msg + "\n" NOR);
	tell_object(obj, sprintf("%s告诉你："+BCYN+HIY+"%s\n" NOR, me->name(1)+"("+me->query("id")+")", msg));
	obj->set_temp("reply", me->query("id"));
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;
	if( ob = find_player(to) ) {
		if( cname )
			tell_object(ob, sprintf(HIY "%s(%s@%s)告诉你：%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIY "%s@%s 告诉你：%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
指令格式：tell <某人> <讯息>

你可以用这个指令和其他地方的使用者说话。

其他相关指令：reply
HELP
	);
	return 1;
}
