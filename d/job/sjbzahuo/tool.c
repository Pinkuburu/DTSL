
#include <weapon.h>

inherit STAFF;

int do_action();

void create()
{
        set_name("扫帚", ({ "sao zhou","sao","zhou" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("no_save",1);
                set("long","这是用来扫除的扫帚。\n");
		set("material", "wood");
        }
        init_staff(10,20,20);

       set("wield_msg", "$N把$n紧紧地握在手中。\n");
        set("unwield_msg", "$N松开了手中的$n。\n");

        setup();
}

void init()
{
   add_action("do_action","dasao");
}

int do_action()
{
   object ob;
   string here;
   
   ob=this_player();
   
   if(!ob->query_temp("sjb_saochu"))
  return notify_fail("你来这里瞎忙活什么呢？\n");
  if(query("owner")!=ob)
  return notify_fail("这不是你的扫帚。\n");
  if(ob->query_temp("weapon")!=this_object())
  return notify_fail("你必须把扫帚拿在手中才可以干活。\n");
  here=base_name(environment(ob));
  if(here!=query("place"))
  return notify_fail("你走错地方了。\n");
  if(query("ok")){
  return notify_fail("这里已经打扫完了，可以回去交差了。\n");}
  
  if(ob->query("sen")<20)
   return notify_fail("你的精神状态太差了，无法再打扫下去了！\n");
   
  if(ob->is_busy())
  return notify_fail("你正忙着呢！\n");
  
  ob->add_temp("sjb_saochu_times",1);
  ob->receive_damage("sen",19+random(5));
  
  message_vision("$N挥起了手中的扫帚，仔细地打扫起来。\n",ob);
  if(ob->query_temp("sjb_saochu_times")>=15+random(5)){
  set("ok",1);
  tell_object(ob,"这里已经打扫完毕，可以回去交差了。\n");}
  ob->start_busy(random(2));
  
  return 1;
}