
inherit ITEM;
#include <ansi.h>
#include <job_money.h>
int do_search(string arg);
void create()
{
   set_name(HIR"通缉令"NOR, ({ "paper"}) );
   set_weight(200);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一张通缉令，你可以用(search)来查找犯人。\n");
     set("material", "白纸");
     set("unit", "张");
     set("value", 0);
     set("no_sell",1);
     set("no_steal",1);
     set("no_drop",1);
     set("no_give",1);
  }
   setup();
}

void init()
{
   add_action("do_search","search");
}

int do_search(string arg)
{
  object ob,killer;int flag;
  object *t;
  object swap_ob;
  int i;
  
  ob=this_player();
  if(!arg||arg!="盗贼")
  return notify_fail("你要搜查什么人？\n");
  if(!ob->query_temp("butou_job"))
  return notify_fail("你没有资格来缉杀盗贼！\n");
  
  t=ob->query_team();
  if(sizeof(t)<2)
  return notify_fail("你没有结队,独自一个人缉杀盗贼太危险了!\n");
  if(sizeof(t)>2)
  return notify_fail("你的队伍中人这么多,好象没什么必要吧?\n");
  for(i=0;i<sizeof(t);i++)
    if(environment(ob)!=environment(t[i]))
      return notify_fail("你的伙伴不在这里，缉杀盗贼太危险了！\n");
  for(i=0;i<sizeof(t);i++)
    if(!t[i]->query_temp("butou_job"))
      return notify_fail("你的队伍中混杂了其他人，无法缉杀盗贼！\n");
  if(query("where")!=base_name(environment(ob)))
  return notify_fail("你查找了一会，发现盗贼好象不在这里。\n");
  if(query("no_search"))
  return notify_fail("加油！加油！\n");
 
  if(t[0]->query("combat_exp")>t[1]->query("combat_exp"))
   swap_ob=t[0];
  else swap_ob=t[1];
  
  set("no_search",1);
  killer=new("/d/job/butou/killer");
  killer->set("combat_exp",swap_ob->query("combat_exp")+100000);

  copy_hp_item(swap_ob,killer,"kee");
  copy_hp_item(swap_ob,killer,"gin");
  copy_hp_item(swap_ob,killer,"sen");
  killer->set("max_force",swap_ob->query("max_force"));
  killer->set("force",swap_ob->query("max_force"));
  set_all_skill(killer,swap_ob->query("max_pot")-80);
  for(i=0;i<sizeof(t);i++)
  killer->add_array("target_id",t[i]->query("id"));
  killer->set_temp("apply/armor",50+random(50));
  killer->move(environment(ob));
  message_vision(HIW"$N突然纵身跃出，朝$n喝道：既然被你们发现，只好杀你灭口了！\n"NOR,
                 killer,ob);
  for(i=0;i<sizeof(t);i++)
    killer->kill_ob(t[i]);
  message_vision("$N一阵慌乱，手中的"+query("name")+"掉到了地上。\n",ob);
  destruct(this_object());
   return 1;
}