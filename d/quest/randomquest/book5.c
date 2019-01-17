
#include <ansi.h> 
inherit ITEM;

int do_apply(string arg);

void create()
{
   set_name("《武学心法》", ({"book"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("eff_times",1);
                set("rumor",1);
                set("long","这是一本《武学心法》，你可以领会[linghui]它来提高自己的武功。\n");
               
        }
}


void init()
{
   add_action("do_apply","linghui");
   if(userp(environment(this_object()))){
   	set("no_give",1);
   	set("no_get",1);
   	set("no_drop",1);
   	set("no_steal",1);}
}

int do_apply(string arg)
{
    object ob;
    
    ob=this_player();
    
    if(!arg)
    return notify_fail("请使用 linghui xx 的格式。\n");
    if(!ob->query_skill(arg,1))
    return notify_fail("你没有学过这个技能。\n");
    
    if(query("eff_times")<=0){
    delete("no_get");
   delete("no_give");
   delete("no_steal");
   delete("no_drop");
    return notify_fail("这本书已经没有什么用处了。\n");}
    
    message_vision(HIY"$N"+HIY+"看了看手中的"+name()+"，顿时觉得"+to_chinese(arg)+"有了进一步的提高！\n"NOR,ob);
    
    ob->improve_skill(arg,ob->query_int()*ob->query("max_pot")*2/3);
    
    add("eff_times",-1);
    
    if(query("eff_times")<=0)
     call_out("dest_ob",5);
       
    return 1;
}

void dest_ob()
{
   tell_object(environment(this_object()),name()+"慢慢变成了碎片，被风吹散了。\n");
   destruct(this_object());
   return;
}