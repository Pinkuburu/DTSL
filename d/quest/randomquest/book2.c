
#include <ansi.h> 
inherit ITEM;

int do_apply(string arg);

void create()
{
   set_name("《狮子印卷》", ({"book"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("eff_times",2);
                set("rumor",1);
                set("random_quest",1);
                set("long","这是一本《狮子印卷》，你可以使用[shiyong]它来提高自己的武功。\n");
               
        }
}


void init()
{
   add_action("do_apply","shiyong");
   if(userp(environment(this_object()))){
   	set("no_give",1);
   	set("no_get",1);
   	set("no_drop",1);
   	set("no_steal",1);}
}

int is_get_of(object me,object ob)
{
   object *inv;
   int i;
   
   inv=all_inventory(me);
   for(i=0;i<sizeof(inv);i++)
    if(inv[i]->query("random_quest"))
      return notify_fail("你捡不起来这个东西。\n");
   return 1;
}

int do_apply(string arg)
{
    object ob;
    object target;
    string target_name;
    int ap,vp;
    
    ob=this_player();
    
    if(!arg||sscanf(arg,"on %s",target_name)!=1)
    return notify_fail("请使用 shiyong on 目标 的格式。\n");
    if(!objectp(target=present(target_name,environment(ob))))
    return notify_fail("你周围没有这个人。\n");
    if(!ob->is_fighting(target))
    return notify_fail("这不是你正在战斗的目标。\n");
    
    if(query("eff_times")<=0){
    delete("no_get");
   delete("no_give");
   delete("no_steal");
   delete("no_drop");
    return notify_fail("这个印卷已经没有什么用处了。\n");}
    
    message_vision(HIY"$N"+HIY+"看了看手中的"+name()+"，顿时觉得武学修为有了进一步的提高！\n"NOR,ob);
    message_vision(MAG"\n$N"+MAG+"鼓动丹田，只见气劲猛地朝$n"+MAG+"冲去！\n"NOR,ob,target);
    ob->add_temp("apply/dodge",200);
    
    add("eff_times",-1);
    
    if(query("eff_times")<=0)
     call_out("dest_ob",5);
    
    ap=COMBAT_D->get_attack(ob,target,ob->query("actions"),0);
    vp=COMBAT_D->get_dodge(ob,target);
  
    if(living(target)&&(((ap-vp*2/3)>50+random(50))||!living(target)||random(ap+vp)>vp
     ||vp<3*ap)){
     	 message_vision(YEL"$N"+YEL+"被气劲打中，神志顿时模糊不清！\n"NOR,target);
         target->set("sen",2);}
    else
      message_vision("$N经验丰富，避开了$n的手掌！\n",target,ob);
    
    ob->add_temp("apply/dodge",-200);
    
    return 1;
}

void dest_ob()
{
   tell_object(environment(this_object()),name()+"慢慢变成了碎片，被风吹散了。\n");
   destruct(this_object());
   return;
}