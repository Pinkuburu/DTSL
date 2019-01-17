
inherit ITEM;
#include <ansi.h>
#include <job_money.h>

int do_action(string arg);

void create()
{
   set_name(HIW"卷轴"NOR,({ "juan zhou","juan","zhou" }));    
   set("long", "这是突厥用来和密探接应的卷轴。\n");       
  set("unit","个");
  set("no_get",1);
  set("no_give",1);
  set("no_drop",1);
   setup();
  
}
void init()
{
  add_action("do_action","jieying");
}

string *msg=({
"$N朝着$n冷笑道：你今天撞到我手里，算你倒霉！！",
"$N大叫一声：突厥的走狗，我早就想杀你了！！",
"$N吐了口吐沫，朝$n喊道：你这个密探今天就拿命来吧！！",
});

int do_action(string arg)
{
  object ob,target;
  string pass,name;
  
  ob=this_player();
  
  if(!arg||sscanf(arg,"%s with %s",pass,name)!=2)
  return notify_fail("你要用什么暗号和谁接应？\n");
  if(!objectp(target=present(name,environment(ob))))
  return notify_fail("这里没有这个人！\n");
  if(target->query("target")!=ob)
  return notify_fail("这不是你要接应的目标！\n");
  
  if(target->query("pass_ok"))
  return notify_fail(target->name()+"低声道：暗号已经对过了，快带我回定襄吧！\n");
  
  if(ob->is_busy())
  return notify_fail("你正忙着呢！\n");
  
  if(!living(target))
  return notify_fail("你先把对方弄醒吧！\n");
  
  if(pass!=query("pass")){
  
  tell_object(ob,"\n你朝"+target->name()+"低声说道："+HIY+pass+NOR"。\n");
  tell_object(ob,"\n"+target->name()+"很疑惑地看着你。\n");
  ob->start_busy(3);//防止连续问
  return 1;}
  
  tell_object(ob,"\n你朝"+target->name()+"低声说道："+HIY+pass+NOR"。\n");
  tell_object(ob,"\n"+target->name()+"低声说道：原来是自己人！\n");
  message("vision",ob->name()+"和"+target->name()+"悄悄说了几句话。\n",
        environment(ob),ob);
  
  target->set("pass_ok",1);
  
  target->set_leader(ob);
  tell_object(ob,"\n"+target->name()+"决定跟随你一起行动。\n");
  
  call_out("killer_come",30+random(10),ob,target);
  return 1;
}

void killer_come(object ob,object target)
{
   object killer;
   
   if(!ob||!target)
    return;
   
   killer=new(__DIR__"killer");
   killer->set_status(ob);
   
   tell_object(ob,BLU"\n突然一阵杀气朝"+target->name()+"袭去！！\n\n"NOR);
   killer->move(environment(target));
   message_vision("\n"+msg[random(sizeof(msg))]+"\n\n",killer,target);
   
   copy_hp_item(ob,target,"kee",3/2);
   ob->add_temp_array("job_temp_killer",killer);
   killer->kill_ob(target);
   return;
}
   
   