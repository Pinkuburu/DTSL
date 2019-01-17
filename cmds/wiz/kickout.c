// kickout.c

#include <ansi.h>
#include <command.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string tmpstr;
	if( me!=this_player(1) ) return 0;
	if( !arg || sscanf(arg, "%s", arg)!=1 ) return notify_fail("你要把谁踢出去？\n");
        ob = LOGIN_D->find_body(arg);
        if (!ob) return notify_fail("咦... 有这个人吗?\n");
                if (    !living(ob)
                ||      !ob->is_character()
                ||      ob==me )
			return notify_fail("ob error!\n");
	message_vision( HIW "$N把$n踢出了大唐。\n" NOR, me,ob);
	seteuid(ROOT_UID);
        ob->save();
        destruct(ob);
	seteuid(getuid());
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : kickout <某人>

强制某个玩家退出大唐。
HELP);
    return 1;
}

