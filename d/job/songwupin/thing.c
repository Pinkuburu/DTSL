
inherit ITEM;
#include <ansi.h>
#include <job_money.h>
mapping name=(["银玉镯":"yu zhuo","手信":"letter","请贴":"tie",
"经书":"book","玉尺":"yu chi","棺材报价单":"dan","镖印":"yin",
]);
int do_give(string arg);
void create()
{
   string *na;int i;
   na=keys(name);
   i=random(sizeof(na));
   set_name(na[i], ({name[na[i]]}));
   set_weight(600);
   if( clonep() )
     set_default_object(__FILE__);
   else {
   set("unit","个");
    set("owner",1);
   }
   setup();
}
void init()
{
  add_action("do_give","song");
}

int do_give(string arg)
{
  object ob,target;
  int exp,coin,pot;
  ob=this_player();
  if(!arg) return notify_fail("你要把"+this_object()->name()+"给谁？\n");
  if(!objectp(target=present(arg,environment(ob))))
  return notify_fail("这里没有这个人！\n");
  if(this_object()->query("owner")!=
     base_name(target)||!ob->query_temp("job/rong_job"))
  return notify_fail("对方不接受这个东西！\n");
  ob->delete_temp("job/rong_job");
  ob->delete_temp("dtsl_job");
  ob->set("busy_time",time());
  if(ob->query("combat_exp")<150000)
  exp=ob->query("max_pot")/3;
  else exp=200+random(30);
  if(ob->query("combat_exp")<1000000)
  pot=ob->query("max_pot")/4;
  else pot=120+random(10);
  coin=RONG_JOB;
  ob->add("combat_exp",exp);
  ob->add("potential",pot);
  ob->add("deposit",coin);
  add_shili(ob,exp/3,coin/2);
  tell_object(ob,"你擦了把汗，在这次行动中你得到了"+HIW+chinese_number(exp)+NOR+"点经验值.\n"+
                 HIY+chinese_number(pot)+NOR+"点潜能"+chinese_number(coin)+"文铜钱\n");
  tell_object(ob,target->name()+"笑道：谢谢了！\n");
  tell_object(ob,"你的钱庄存款增加了！\n");
  destruct(this_object());
  return 1;
}
