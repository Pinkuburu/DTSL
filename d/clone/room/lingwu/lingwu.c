int do_lingwu(string arg)
{
  object ob;
  ob=this_player();
  if(!arg)
  return notify_fail("你要领悟什么内功？\n");
  if(arg!=environment(ob)->query("force"))
  return notify_fail("这里不能领悟这种内功！\n");
  if(ob->query_skill(arg,1)>=300)
  return notify_fail("这个内功你已经领悟到上限了，无法继续提高了！\n");
  if(ob->query("potential")<=0)
  return notify_fail("你的潜能太低了，无法进行领悟！\n");
  if(ob->query("gin")<300)
  return notify_fail("你的精血不足，无法进行领悟！\n");
  ob->improve_skill(arg,ob->query("potential")*30);
  ob->set("potential",0);
  ob->set("gin",1);
  tell_object(ob,"你领悟起"+to_chinese(arg)+"来，觉得有了些收获。\n");
  return 1;
}