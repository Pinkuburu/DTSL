// quit.c

#include <command.h>
#include <ansi.h>
#include <job_money.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() 
{
	seteuid(getuid());
	set("channel_id", "离线指令");
}

int main(object me)
{
	int i,j;
	object link_ob,where;
	where=environment(me);
	link_ob = me->query_temp("link_ob");
	if(me->query_temp("quitting"))
	return notify_fail("正在退出游戏。\n");
	if (me->query_temp("no_move")) return notify_fail("你被定住了，哪里退得出游戏！\n");
 if(me->query("pker")&&time()-me->query("pker_time")<1800)
 return notify_fail("你现在是通缉犯，暂时不能退出游戏！\n");
	if(environment(me)&&!environment(me)->query("exits"))
	return notify_fail("这里不能退出游戏。\n");
	if(!me->query_temp("suicide_countdown")&&!me->query_temp("netdead")){
		if(me->is_busy()) return notify_fail("( 你上一个动作还没有完成，不能退出。)\n");
	} 
	if( !wizardp(me) && environment(me) && environment(me)->query("no_quit") && link_ob ) return notify_fail("这里不准退出游戏。\n");

	where=environment(me);
	link_ob = me->query_temp("link_ob");
	
	// We might be called on a link_dead player, so check this.
	if( link_ob ){
	// Are we possessing in others body ?
		if( link_ob->is_character()){
			write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}
		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->save();
		destruct(link_ob);
	}
//    me->set("startroom",file_name(where));
	me->set_temp("quitting",1);
	write(YEL"\n现在准备离开游戏... ...\n\n"NOR);
	CHANNEL_D->do_channel(this_object(), "sys",me->name()  +"(" + me->query("id") + ")"+"准备离开游戏了。");
	if(!wizardp(me))
	call_out("do_quit",8,me,link_ob);
	else{
	tell_object(me,"\n作为巫师，你可以迅速离线。\n\n");
	call_out("do_quit",1,me,link_ob);}
	return 1;
}

void do_quit(object me,object link_ob)
{
  
  object *inv;
  int i,j;
  
  if(!me) return;
  
  inv=all_inventory(me);
  if( !wizardp(me) && (!link_ob || (link_ob && !link_ob->is_character()))){
		
		
		for(i=0; i<sizeof(inv); i++){
		     if(inv[i]->unequip());
		   	if(!inv[i]->query_autoload())
			do_drop(me, inv[i]);}
	}

  j=JOBSYS_D->clear_job_npc(me);
  tell_object(me,HIW"\n\n如果你是使用公用机器登录，请确认 Zmud 中是否保留你帐号的密码，\n"+ 
                 HIR+"以避免你的帐号被他人盗用！\n"+NOR+
                 HIY+"欢迎下次光临！再见！！\n\n"NOR); 
  message("system", me->name() + "离开游戏。\n", environment(me), me);
  CHANNEL_D->do_channel(this_object(), "sys",me->name()  +"(" + me->query("id") + ")"+"离开游戏了。");
  CHANNEL_D->do_channel(this_object(), "sys","清除了 "+j+" 个任务变量\n");
  me->delete_temp("dtsl_job");
  
  if(me->query_temp("medicine_add_temp_force")){
    me->add("force",-me->query_temp("medicine_add_temp_force"));
    if(me->query("force")<0)
     me->set("force",0);
  }
  
  if(me->query_temp("medicine_add_temp_maxforce")){
    me->add("max_force",-me->query_temp("medicine_add_temp_maxforce"));
    if(me->query("max_force")<0)
     me->set("max_force",0);
  }
  
  me->save();
  destruct(me);
  return;
}

int do_drop(object me, object obj)
{
	if (obj->query("no_drop"))
	{
		destruct(obj);
		return 0;
	}
	if (obj->move(environment(me)))
	{
		if(obj->is_character()) message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
		else 
		{
			message_vision( sprintf("$N丢下一%s$n。\n", obj->query("unit")), me, obj );
			if( !obj->query("value") && !obj->value()&&!obj->is_character() )
			{
				tell_object(me,"因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
				destruct(obj);
			}
		}
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
指令格式 : quit

当你需要暂时退出游戏时，可利用此一指令。
HELP);
	return 1;
}
