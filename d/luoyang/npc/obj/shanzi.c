
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name("扇子", ({ "shan zi","shan","perform_quest_zhehuabaishi_obj" }) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "把");
     set("no_save",1);     
     set("material", "iron");
     set("times",3);
     set("no_give",1);
     set("long", "这是一把纸扇子。\n");
     set("wield_msg", "$N拿出一把$n握在手中,随手扇了几下。\n");
     set("unequip_msg", "$N将手中的$n折起，放入怀中。\n");
   }
   init_blade(15,90,90);
   setup();
}

void init()
{
   add_action("do_hua","draw");

}

int do_hua(string arg)
{
   object ob,target;
   object obj;
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("你要在扇子上画谁的像？\n");
   if(!objectp(target=present(arg,environment(ob))))
   return notify_fail("这里没有这个人。\n");
   if(!userp(target))
   return notify_fail("你还是找个玩家来画吧！\n");
   if(target->query("gender")=="男性")
   return notify_fail("不是告诉你要画女性吗？\n");
   if(target->query("age")>60)
   return notify_fail("这么老的女子还是不要画了。\n");
   if(ob==target)
   return notify_fail("画你自己？？\n");
   
   message_vision("$N拿出画笔，将$n的像画到了扇子上。\n",ob,target);
   ob->add("perform_quest/zhi_damage",target->query("per"));
   if(query("drawed"))
   set("drawed",query("drawed")+"，"+target->name());
   else
   set("drawed",target->name());
   
   add("times",-1);
   ob->add("perform_quest/zhi_times",1);
   
   if(ob->query("perform_quest/zhi_times")>=3
     ||query("times")<=0){
     message_vision("\n$N突然之间领会了花间追求的美好事物之意，不禁哈哈一笑，扔掉了扇子！\n",ob);
     obj=new(__DIR__"shanzi2");
     obj->set("long","这是花间弟子的成长纪念扇子。\n"+
                     "上面画着美女，分别是："+query("drawed")+"。\n");
     obj->move(ob);
     destruct(this_object());
     return 1;
   }
   
   return 1;
}