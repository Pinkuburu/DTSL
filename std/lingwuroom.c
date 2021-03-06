inherit ROOM;

#include <org.h>
#include <ansi.h>

#define OB this_player()

string *skills=({"dodge","unarmed","parry","finger","strike",
"leg","cuff","force","sword","blade","staff","fork","axe","whip",
"hammer","spear","stick","dagger"});

void init()
{
  add_action("do_lingwu","lingwu");
  
}

int do_lingwu(string arg)
{
  string str;
  if(!arg)
  return notify_fail("你要领悟什么？\n");
  if(member_array(arg,skills)==-1)
  return notify_fail("这个技能不能用领悟来提高。\n");
  if(OB->query_skill(arg,1)<200)
  return notify_fail("你的技能太低，不足以领悟。\n");
  if(OB->query("gin")<=15)
  return notify_fail("你的精不足，无法领悟！\n");
  if(OB->query("potential")<=0)
  return notify_fail("你的潜能不足，无法领悟！\n");
  if(OB->is_busy())
  return notify_fail("你正忙着呢！\n");
  
  if(OB->query("shili/name")&&
     !ORG_D->if_get_upper(OB,arg))
  return notify_fail("你还是先提高自己帮会的技能上限吧！\n");
  
  if(OB->query_temp("mark/lingwu"))
  return notify_fail("你已经开始领悟了！\n");
  message_vision("$N坐了下来，开始冥思领悟武学。\n",OB);
  str=YEL+OB->name()+"静静坐在那里，正在冥思领悟"NOR;
  OB->set_temp("apply/short",({str}));
  OB->set_temp("mark/lingwu",1);
  OB->start_busy((:call_other,this_object(),"doing_lingwu",OB,arg:),
                 (:call_other,this_object(),"halt",OB:));
   return 1;
}

int doing_lingwu(object ob,string arg)
{
   int i;
   if(ob->query("potential")>=30)
   i=30;
   else i=ob->query("potential");
   if(ob->query("shili/name"))
   ob->improve_skill(arg,(ob->query_int()*4/5+random(10))*i
                          );
   else
   ob->improve_skill(arg,(ob->query_int()/6+random(10))*i
                          );
   if(ob->query("gin")>15)
   ob->receive_damage("gin",15);
   if(ob->query("potential")>30)
   ob->add("potential",-30);
   else ob->set("potential",0);
   if(ob->query("gin")<15||ob->query("potential")<=0){
   message_vision(HIY"$N觉得头脑一阵眩晕，连忙站了起来。\n"NOR,ob);
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
