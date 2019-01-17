
#include <ansi.h>

int exert(object me, object target)
{
	string str,arg;
	
	if(me->is_fighting())
	return notify_fail("战斗中不能领悟长生诀！\n");
	
	if(me->is_busy())
	return notify_fail("你正忙着呢！\n");
	
	if(target!=me)
	return notify_fail("你只能自己领悟长生诀！\n");
	
	message_vision("$N坐了下来，开始冥思领悟长生诀。\n",me);
        str=HIY+me->name()+HIY+"静静坐在那里，正在冥思领悟"NOR;
	me->set_temp("apply/short",({str}));
	arg="changsheng-jue";
        me->start_busy((:call_other,this_object(),"doing_lingwu",me,arg:),
                 (:call_other,this_object(),"halt",me:));
        return 1;
}

int doing_lingwu(object ob,string arg)
{
   int i;
   if(ob->query("potential")>=30)
   i=30;
   else i=ob->query("potential");
  
   ob->improve_skill(arg,(ob->query_int()/3+random(10))*i
                          );  
   if(ob->query("gin")>15)
   ob->receive_damage("gin",15);
   if(ob->query("potential")>30)
   ob->add("potential",-30);
   else ob->set("potential",0);
   if(ob->query("gin")<15||ob->query("potential")<=0){
   message_vision(HIY"$N"+HIY+"觉得头脑一阵眩晕，连忙站了起来。\n"NOR,ob);
   ob->delete_temp("apply/short");
   ob->delete_temp("mark/lingwu");
   return 0;}
   else return 1;
}

int halt(object ob)
{
  message_vision("$N长长地嘘了口气，缓缓地站了起来。\n",ob);
  ob->delete_temp("apply/short");
  ob->delete_temp("mark/lingwu");
  return 1;
}

	
