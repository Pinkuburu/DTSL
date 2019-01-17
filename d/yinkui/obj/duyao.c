#include <ansi.h>
inherit ITEM;

int do_du(string arg);
void create()
{
   set_name(HIR"毒龙散"NOR, ({"du longsan","du","san"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "这是阴葵派的不传毒药[毒龙散]。\n");
	 set("poision",10);
     set("unit", "个");
     set("value", 200);
     
   }

}

void init()
{
	add_action("do_du","xiadu");
}

int do_du(string arg)
{
   object victim,ob,me;
   me=this_player();
   ob=this_object();
	if(!arg) return notify_fail("你想给谁下毒?\n");
   if(!objectp(victim=present(arg,environment(me))))
	   return notify_fail("这里没有这个人!\n");
   victim->apply_condition("dulongsan",6+random(6));
   if(userp(victim))
	   tell_object(victim,"你感到有些不对,原来是"+me->name()+"给你下了毒药!\n");
   else victim->kill_ob(me);
   destruct(ob);
   return 1;
}
