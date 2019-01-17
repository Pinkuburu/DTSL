#include <ansi.h>
#include <job_money.h>
inherit ITEM;
int do_search(string arg);
void create()
{
   set_name(HIR"缉杀令"NOR, ({ "paper"}) );
   set_weight(200);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一张缉杀令，你可以用(search)来查找犯人。\n");
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
  
  ob=this_player();
  if(!arg||arg!="陶叔胜")
  return notify_fail("你要搜查什么人？\n");
  if(!ob->query_temp("shang_kill_pantu"))
  return notify_fail("你没有资格来缉杀陶叔胜！\n");
  if(ob->query_temp("shang_kill_pantu/where")!=base_name(environment(ob)))
  return notify_fail("你查找了一会，发现陶叔胜好象不在这里。\n");
  if(query("no_search"))
  return notify_fail("加油！加油！\n");
  set("no_search",1);
  killer=new(__DIR__"killer");
  killer->set("combat_exp",ob->query("combat_exp"));
  if("/cmds/usr/hp.c"->get_pot(killer));
  copy_hp_item(ob,killer,"kee");
  copy_hp_item(ob,killer,"gin");
  copy_hp_item(ob,killer,"sen");
  killer->set("max_force",ob->query("max_force"));
  killer->set("force",ob->query("max_force"));
  set_all_skill(killer,ob->query("max_pot")-100);
  killer->set("target_id",ob->query("id"));
  killer->set_temp("apply/armor",50+random(50));
  killer->move(environment(ob));
  message_vision(HIW"$N突然纵身跃出，朝$n喝道：既然被你发现，只好杀你灭口了！\n"NOR,
                 killer,ob);
  killer->kill_ob(ob);
  message_vision("$N顺手扔掉了"+query("name")+"，目不转睛地盯着$n的行动！\n",
                 ob,killer);
  destruct(this_object());
   return 1;
}