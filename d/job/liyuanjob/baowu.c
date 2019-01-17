#include <ansi.h>
#include <job_money.h>
inherit ITEM;
mapping name=([
HIY"九转灵珠"NOR:"jiuzhuan lingzhu",HIW"夜明珠"NOR:"yeming zhu",HIG"翡翠项链"NOR:"necklace",HIW"白玉白虎"NOR:"tigger",
HIY"金娃娃"NOR:"jin wawa",HIC"避水珠"NOR:"bishui zhu",HIG"翡翠珊瑚"NOR:"shan hu",HIW"白玉美人"NOR:"baiyu meiren",
HIC"夜光手镯"NOR:"shou zhuo",HIY"金砖"NOR:"jin zhuan",HIW"白玉萧"NOR:"xiao",HIG"猫眼"NOR:"mao yan",HIG"玛瑙"NOR:"ma nao",
HIG"琴谱"NOR:"qin pu",HIY"金项圈"NOR:"xiang quan",HIY"钻石"NOR:"zuan shi",HIW"天山雪莲"NOR:"xue lian",HIW"千年人参"NOR:"ren shen",
]);
void create()
{
   string *n;int i;
   n=keys(name);
   i=random(sizeof(n));
   set_name(n[i],({name[n[i]]}));
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("no_sell",1);
     set("no_give",1);
     set("no_drop",1);
     set("unit", "个");
     set("value", 0);
   }
   setup();
}
int is_get_of(object pal,object ob)
{
  object killer,killer2;
  if(query("owner")==pal->query("id"))
  return 1;
  if(query("target")!=pal)
 return notify_fail("你拣不起来这个宝物！\n");
  killer=new(__DIR__"killer4");
  killer2=new(__DIR__"killer4");
  killer->set("combat_exp",pal->query("combat_exp"));
 if("/cmds/usr/hp.c"->get_pot(killer));
 copy_hp_item(pal,killer,"gin");
 copy_hp_item(pal,killer,"kee");
 copy_hp_item(pal,killer,"sen");
  set_all_skill(killer,pal->query("max_pot")-90);
  copy_object(killer2,killer);
  set_all_skill(killer2,pal->query("max_pot")-100);
  killer->move(environment(pal));
  killer2->move(environment(pal));
  message_vision("$N大声道：我辛辛苦苦从长安偷来的东西，你也来抢？真是不要命了！\n",killer);
  killer->kill_ob(pal);
  killer->set_leader(pal);
  pal->kill_ob(killer);
  killer2->kill_ob(pal);
  killer2->set_leader(pal);
  pal->kill_ob(killer2);
  set("owner",pal->query("id"));
  call_out("move_baowu",2,killer,killer2);
  return 1;
}

void init()
{
  if(!query("last_time"))
   set("last_time",time());
}

int clean_up()
{
  if(time()-query("last_time")<1800)
   return 0;
  return 1;
}

void move_baowu(object killer,object killer2)
{
  if(random(2)==1)
   if(!killer) return;
   else{
   this_object()->move(killer);
   message_vision(HIC"$N眼急手快，噌地一下抢走了"+query("name")+"\n"NOR,killer);
   return;}
  else{
  if(!killer2) return;
   else{
   this_object()->move(killer2);
   message_vision(HIC"$N眼急手快，噌地一下抢走了"+query("name")+"\n!"NOR,killer2);
   return;}}
}