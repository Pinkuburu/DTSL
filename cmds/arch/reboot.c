// reboot.c

#include <login.h>
#include <ansi.h>
#include <obj.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object npc;
        int i;
        
	if( me != this_player(1) ) return 0;
	
	if( SECURITY_D->get_wiz_level(me) < SECURITY_D->get_wiz_level("(arch)"))
		return notify_fail("只有 (arch) 以上的巫师才能重新启动" + MUD_NAME + "\n");
        if(!arg||sscanf(arg,"%d",i)!=1)
         i=1;
        if(i>20)
        return notify_fail("时间也太长了吧？！\n");
	seteuid(getuid());

        message("system",
                HIY    "大唐双龙（DAtang ShuangLong）将在"+HIR+chinese_number(i)+HIY+"分钟后重新启动（ＲＥＢＯＯＴ）。\n\n" NOR,
                users() );
        call_out("countdown", 60,i);
        return 1;
}

private void countdown(int min)
{
 int i;object *ob;
	min--;
	if( min ) {
		message("system",
                        HIR     "\t\t大唐双龙（DAtang ShuangLong）在" + chinese_number(min) + "分钟后重新启动（ＲＥＢＯＯＴ）！\n\n"NOR,
			users() );
		call_out("countdown", 60, min);
	} else {
		message("system",
                        HIW "大唐双龙（DAtang ShuangLong）重新启动（ＲＥＢＯＯＴ）．．．\n"NOR,
			users() );
 ob=users();
 for(i=0;i<sizeof(ob);i++){
 if(!interactive(ob[i])) continue;
ob[i]->delete("busy_time");
ob[i]->save();}
                call_out("do_shutdown",6);
	}
}

private void do_shutdown()
{
	shutdown(0);
}
int help (object me)
{
        write(@HELP
指令格式: reboot
 
重新起动游戏, 系统会开始倒数计时, 几分钟後重新起动。
 
HELP
);
        return 1;
}
 
