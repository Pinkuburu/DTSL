
#include <ansi.h>
#include <job_money.h>
inherit ITEM;
int do_give(string arg);
void create()
{
   set_name(YEL"订货单"NOR, ({ "order" }) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","这是一张买卖王的订货单。\n");
	 set("order_job",1);
	 set("no_give",1);
	 set("no_drop",1);
	 set("give_object",1);
         set("unit", "张");
   }
   setup();
}

void init()
{
   add_action("do_give","songdan");
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
    return notify_fail("你要把订货单送给谁？\n");
    if(!objectp(ob=present(arg,environment(who))))
    return notify_fail("这里没有这个人！\n");
    if(!who->query_temp("order_job")||query("owner")!=who)
    return notify_fail("这张订货单好象不是让你来送的。\n");
    if(query("target")!=(ob))
    return notify_fail("你送错人了！\n");
        
        JOBSYS_D->give_reward_tradejob(who);
        
	who->delete_temp("order_job");
	who->delete_temp("dtsl_job");
	who->delete_temp("need_killer");
	who->delete_temp("need_killer_flags");
	who->set("busy_time",time());
	
	tell_object(who,"你成功地将订货单送给了"+ob->name()+"！\n");	
	message_vision("\n$N挥了挥手，下次再合作吧！\n$N匆匆走了。\n",ob);
	destruct(ob);
	destruct(this_object());
	return 1;
}
