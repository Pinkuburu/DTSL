
#include <weapon.h>

inherit STAFF;

int do_action();

void create()
{
        set_name("锄头", ({ "chu tou","chu","tou" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一把看起相当普通的锄头");
                set("material", "wood");
                set("no_give",1);
                set("no_get",1);
                set("no_drop",1);
                set("no_steal",1);
                set("no_save",1);
        }
        init_staff(10,20,20);

      set("wield_msg", "$N把$n紧紧地握在手中。\n");
        set("unwield_msg", "$N松开了手中的$n。\n");

// The setup() is required.

        setup();
}

void init()
{
  add_action("do_action","wa");
}

int do_action()
{
   object ob,medicine,tool;
   
   ob=this_player();
   
   tool=ob->query_temp("weapon");
   
   if(ob->is_busy())
   return notify_fail("你正忙着呢！\n");
   if(ob->is_fighting())
   return notify_fail("你还是先打仗吧！\n");
   
   if(!objectp(tool)||tool!=this_object())
    return notify_fail("你应该先把锄头装备起来再挖药。\n");
    
   if(query("place")!=base_name(environment(ob))+".c")
    return notify_fail("你挖药的地点不对。\n");
   
   if(ob->query_temp("wei_ok"))
   return notify_fail("这里的草药已经挖完了，可以回去找韦华佗了。\n");
   
   if(ob->query_temp("wei_job/count")==12)
	{
		medicine=new(__DIR__"caoyao");
		medicine->set("owner",ob);
		medicine->move(ob);
		message_vision("$N挖到了一个"+medicine->name()+"\n",ob);
		//ob->delete_temp("wei_job");
		ob->set_temp("wei_ok",1);
		return 1;
	}
   ob->add_temp("wei_job/count",1+random(1));
   
	ob->receive_damage("sen",20+random(10));
	ob->start_busy(random(2));
	message_vision("$N挥起"+tool->name()+"挖了起来！\n",ob);
	return 1;
}