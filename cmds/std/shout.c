// shout.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !wizardp(me) )
		if(me->query("force")<2000)
		return notify_fail("你的内力不足以纵声长啸。\n");
	if(!wizardp(me)&&environment(me)->query("no_shout"))
	   if(stringp(environment(me)->query("no_shout")))
	     return notify_fail(environment(me)->query("no_shout"));
	   else return notify_fail("这里禁止纵声长啸！\n");
	if(environment(me)->query("sleep_room"))
	return notify_fail("卧室内禁止大声喧哗！\n");
	if(arg==me->query_temp("last_shout_msg"))
	return notify_fail("同一句台词你喊那么大声干什么？！\n");
	if (!arg) return notify_fail("你想要大叫什么？\n");
	if(!wizardp(me))
	me->add("force",-2000);
	me->set_temp("last_shout_msg",arg);
	shout( HIW + me->name() +HIW+ "纵声长啸：" + arg + NOR + "\n");
	write(HIW + "你纵声长啸：" + arg + NOR + "\n");
	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : shout <讯息>
 
这个指令让你将 <讯息> 传送出去, 所有正在游戏中的人都
会听见你的话.
 
see also : tune
HELP
    );
    return 1;
}
 
