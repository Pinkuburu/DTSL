
#include <ansi.h>
#include <job_money.h>
inherit ITEM;
int do_give(string arg);
void create()
{
   set_name(YEL"密涵"NOR, ({ "letter","xin" }) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","这是一封阴癸派的密涵。\n");
	 set("zhu_sx",1);
	 set("no_give",1);
	 set("no_drop",1);
	 set("no_get",1);
	 set("give_object",1);
         set("unit", "封");
   }
   setup();
}

void init()
{
   add_action("do_give","songxin");
}

int is_get_of(object me,object ob)
{
	if(query("owner")!=me)
	return notify_fail("这个东西你捡不起来。\n");
	return 1;
}

int do_give(string arg)
{
    
    object who,ob;
    who=this_player();
    if(!arg)
    return notify_fail("你要把信送给谁？\n");
    if(!objectp(ob=present(arg,environment(who))))
    return notify_fail("这里没有这个人！\n");
    if(!who->query_temp("zhu_sx")||query("owner")!=who)
    return notify_fail("这封信好象不是让你来送的。\n");
    if(query("target")!=(ob))
    return notify_fail("你送错人了！\n");
    
    JOBSYS_D->give_reward_songxin(who);
        
	who->delete_temp("zhu_sx");
	who->delete_temp("dtsl_job");
	who->delete_temp("need_killer");
	who->delete_temp("need_killer_flags");
	tell_object(who,"你成功地将信送给了"+ob->name()+"！\n");	
	message_vision("\n$N一握双拳：咱们后会有期！\n$N匆匆走了。\n",ob);
	destruct(ob);
	destruct(this_object());
	return 1;
}
