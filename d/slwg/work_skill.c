
int do_action(string arg)
{
   object ob;
   string *work_msg;
   
   ob=this_player();
   
   if(ob->query("combat_exp")>20000)
   return notify_fail("你的武功这么高了，还是到外面闯荡江湖吧！\n");
   
   if(ob->is_busy())
    return notify_fail("你正忙着呢！\n");
   
   if(!arg)
   return notify_fail("你要练习什么武艺？\n");
   
   if(arg!=query("lianwu"))
   return notify_fail("这里不能练习这种武艺。\n");
   
   if(ob->query_temp("slwg_job")!=query("lianwu"))
   return notify_fail("没有教头的许可，你不能在这里练习武艺！\n");
   
   if(ob->query("kee")<15)
    return notify_fail("你的精神状态太差了，无法练习武艺！\n");
   if(ob->query("sen")<15)
    return notify_fail("你的精神状态太差了，无法练习武艺！\n");
     
   if(ob->query_temp("slwg_job_ok"))
    return notify_fail(query("over_work"));
   
   if(ob->query_temp("slwg_job_times")>=5+random(5)){
     tell_object(ob,query("over_work"));
     ob->set_temp("slwg_job_ok",1);
     return 1;
    }
    
     ob->add_temp("slwg_job_times",1);
   ob->receive_damage("kee",10+random(5));
   ob->receive_damage("sen",10+random(5));
   
    if(arrayp(query("work_msg"))){
    	work_msg=query("work_msg");
    	tell_object(ob,work_msg[random(sizeof(work_msg))]);
    	}
    else tell_object(ob,query("work_msg"));
    
    ob->start_busy(1+random(1));
    
   return 1;
}