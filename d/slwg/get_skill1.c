
int do_action(string arg)
{
   object ob,target;
   
   ob=this_player();
   
   if(ob->query("combat_exp")>=20000)
   return notify_fail("你的武功这么高了，还是到外面闯荡江湖吧！\n");
   
   if(ob->query("combat_exp")>=10000)
   return notify_fail("你的武功已经不差了，去找教头切磋吧！\n");
   
   if(ob->is_fighting())
    return notify_fail("你快专心战斗吧！\n");
   
   if(ob->is_busy())
    return notify_fail("你快专心战斗吧！\n");
    
   if(time()-ob->query("busy_time")<5+random(4))
    return notify_fail("你还是歇会在切磋吧！\n");
   
   if(!arg)
   return notify_fail("你要和谁切磋技能？\n");
   
   if(!objectp(target=present(arg,environment(ob))))
   return notify_fail("这里没有这个人。\n");
   
   if(!target->query("slwg_jiaotou"))
   return notify_fail("你只能和弟子或教头切磋武艺！\n");
   
   if(COMBAT_D->status(ob,0)<60||COMBAT_D->status(ob,1)<60)
    return notify_fail("你的身体状况太差了，还是先去休息一下吧！\n");
   
   message_vision("$N朝$n一施礼：在下武功低微，还请你多多指教！\n",ob,target);
   
   ob->set("env/wimpy",50);
   ob->start_busy(1);
   target->fight_ob(ob);
   
   return 1;
}