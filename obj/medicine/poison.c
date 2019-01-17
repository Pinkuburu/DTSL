
inherit ITEM;
#include <ansi.h>
int do_tu(string arg);
int do_xiadu();
int do_xishi(string arg);
void create()
{
        set_name("基本毒药", ({ "poison" }) );
        set_weight(10);
        set("medicine_class","poison");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
		set("long","这是一枚毒药。\n");
		
              	              
        }      
        setup();
}

void init()
{
   add_action("do_tu","tu");
   add_action("do_xiadu","xiadu");
   add_action("do_xishi","xishi");
}

int do_tu(string arg)
{
   object me,ob;
   
   me=this_player();
   if(!arg)
   return notify_fail("你要往什么东西上涂抹「"+query("name")+"」？\n");
   if(!objectp(ob=present(arg,me)))
   return notify_fail("你身上没有这个东西！\n");
   if(ob==this_object())
   return notify_fail("恩？你没搞错吧？？\n");
   if(ob->is_character())
   return notify_fail("你看清楚，那个上面能涂毒药吗？！\n");
   if(me->query("pker"))
   return notify_fail("通缉犯还是老实一点吧！\n");
   if(ob->query("skill_type")&&!ob->query("poison_flag"))
   return notify_fail(ob->query("name")+"不是可以涂抹毒药类的兵器，无法在上面涂抹毒药。\n");
   if(ob->query("skill_type")&&me->query("vocation")!="杀手")
   return notify_fail("只有杀手能向兵器上涂毒！\n");
   message_vision("$N在"+ob->query("name")+"涂抹了些"+query("name")+"。\n",
      me);
   ob->set("poison",query("heal_up"));
   destruct(this_object());
   return 1;
}

int do_xiadu()
{
   object ob;
   
   ob=this_player();
   if(ob->query("pker"))
   return notify_fail("通缉犯还是老实一点吧！\n");
   message_vision("$N在地上撒了些"+query("name")+"。\n",ob);
   environment(ob)->set("poison",query("heal_up"));
   destruct(this_object());
   return 1;
}

int do_xishi(string arg)
{
  object ob,corpse;
   
   ob=this_player();
  if(query("name")!="吸尸粉")
  return notify_fail("只有吸尸粉可以从尸体上练毒功。\n");
  if(!arg)
  return notify_fail("你要向什么东西上撒[吸尸粉]？\n");
  if(!objectp(corpse=present(arg,environment(ob))))
  return notify_fail("你旁边没有这个东西！\n");
  if(!corpse->is_corpse())
  return notify_fail("那个东西不是尸体，不能练功！\n");
  if(ob->is_busy())
  return notify_fail("你正忙着呢！\n");
  if(ob->is_fighting())
  return notify_fail("你先打完仗再说吧！\n");
  if(ob->query("force")<ob->query_skill("poison",1))
  return notify_fail("你的内力不足以吸尸！\n");
  if(ob->query_skill("poison",1)<80)
  return notify_fail("你的毒术不够，无法进行吸尸！\n");
  if(ob->query_skill("poison",1)>=ob->query_int()*10)
  return notify_fail("你的毒术已经学到了尽头，无法再继续提高了！\n");
  message_vision("$N把吸尸粉撒到了尸体之上，手掌按在了尸体上。\n",ob);
  tell_object(ob,HIR"你从尸体上不断吸取腐毒之气，觉得毒技有些进步了！\n"NOR);
  tell_object(environment(ob),"只见尸体慢慢地化成了血水。\n");
  ob->start_busy(random(2));
  ob->add("force",-ob->query_skill("poison",1));
  ob->improve_skill("poison",ob->query_int());
  add("use_times",1);
  destruct(corpse);
  if(query("use_times")>=ob->query_skill("poison",1)/10)
   destruct(this_object());
  return 1;
}