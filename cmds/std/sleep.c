// sleep.c
// yanyan@dDtSl
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping fam;
	object where = environment(me);

	seteuid(getuid());
	if ( !where->query("sleep_room")
             || (where->query("no_sleep_room")) )
             return notify_fail("这里不是你能睡的地方！\n");
   
	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if( me->is_fighting() )
		return notify_fail("战斗中不能睡觉！\n");        
    me->set("no_get",1);
    me->set("no_get_from",1);
	me->set("no_steal_from",1);
	
	if(me->query("con")<35)
		call_out("wakeup",10 + 35 - me->query("con"), me);
	else
		call_out("wakeup",10, me);
	write("你一歪身，躺了下来，开始睡觉。\n");
	write("不一会儿，你就进入了梦乡。\n");	    
	tell_room(where,me->query("name")+"一歪身，躺了下来，不一会便进入了梦乡。\n",({me}));
 	me->disable_player(" <睡梦中>");
    // my["con"] is a factor in sleep.
	return 1;
	
}

void wakeup(object me)
{
    int intp;int add;
if (!me){
    return;}

if(me->query_temp("netdead")){
    me->enable_player();
    //me->delete_temp("block_msg/all");
}

	intp=me->query_temp("sleep_interrupt");
    while(environment(me)->is_character())
                me->move(environment(environment(me)));//if someone get you... :-)
    add=time()-intp;
	add=35-add;
	if(add<=0) add=1;//you must sleep again after 30 seconds then you can full all.
	if(me->query("kee")<me->query("eff_kee"))
	me->add("kee", (me->query("eff_kee") - me->query("kee"))/add);
	if(me->query("gin")<me->query("eff_gin"))
	me->add("gin",  (me->query("eff_gin") - me->query("gin"))/add);
	if(me->query("force")<me->query("max_force"))
	me->add("force", (me->query("max_force") - me->query("force"))/2/add);
	if(me->query("sen")<me->query("eff_sen"))
        me->add("sen", (me->query("eff_sen") - me->query("sen"))/add);
	me->enable_player();
	if (add>1)
		message_vision("$N一觉醒来，懒洋洋地活动了一下筋骨。\n",me);
	else
		message_vision("$N一觉醒来，精力充沛地活动了一下筋骨。\n",me);
	//me->delete_temp("block_msg/all");
	me->enable_player();
    me->set_temp("sleep_interrupt",time());
    me->delete("no_get");
    me->delete("no_get_from");
	me->delete("no_steal_from");
	me->start_busy(1);
	if (add>1)
		write("由于睡得太频繁，你觉得精神不是很好。\n");
	else
		write("你觉得精力充沛，该活动一下了。\n");
	if(environment(me)->do_sleep(me));
       return;
}
