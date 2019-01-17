void init()
{
   add_action("do_task","task");
}

int do_task(string arg)
{
  object ob;
  object track;
  
  ob=this_player();
  if(!arg||arg!="ok")
  return notify_fail("请使用 task ok 来复命。\n");
  if(ob->query_temp("liyuan_job/step")!=7)
  return notify_fail("军官眼睛一瞪：无知草民，到这里乱说什么！！\n");
  if(!ob->query_temp("track_target")||
  !objectp(track=ob->query_temp("track_target")))
  return notify_fail("军官一皱眉：运粮的车都丢了，你太没用了！\n");
 
  if(environment(track)!=environment(ob))
  return notify_fail("粮车也不在这里啊，赶快运过来吧！\n");
  if(this_object()->query("task_ok")!=track->query("target_place"))
  return notify_fail("你的粮草车送错了地方！！\n");
  ob->add_temp("liyuan_job/step",1);
  destruct(track);
  ob->delete_temp("track_target");
  tell_object(environment(ob),"马上出来一个小兵，把盐车拉了进去。\n");
  tell_object(ob,this_object()->query("name")+"朝你笑道：谢谢你了！\n");
  return 1;
}

  
