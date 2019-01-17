

#include <weapon.h>

inherit BLADE;
int do_ke(string arg);
void create()
{
set_name("刻刀", ({ "ke dao","dao"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 100);
     set("material", "iron");
     set("long", "这是一把小刻刀，可以在武器上刻上字。\n");
     set("wield_msg", "$N将$n握在手中。\n");
     set("unequip_msg", "$N将手中的$n放回衣兜中。\n");
   }
   init_blade(5,10,10);
   setup();
}

void init()
{ 
	add_action("do_ke","ke");
}

int do_ke(string arg)
{
	object me,ob;
	string obs,name;
	me=this_player();
if(!present("ke dao",me))
return notify_fail("什么？\n");
	if(!arg||
		sscanf(arg,"%s %s",obs,name)!=2)
	return notify_fail("请使用 ke 武器 想刻上去的字\n");
	if(!objectp(ob=present(obs,me)))
		return notify_fail("你找了半天，发现身上根本就没有这个东西。\n");
	if(!ob->query("skill_type"))
		return notify_fail("你仔细看了看，哦，原来那根本就不是武器。\n");
	message_vision("$N拿起"+this_object()->name()+"在"+ob->name()+"上刻起字来。\n",me);
	ob->delete_temp("apply/long");
	ob->set("long",name);
	message_vision("$N擦擦汗，终于刻好了！\n",me);
	return 1;
}
	
