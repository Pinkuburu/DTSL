
inherit ITEM;
int do_linghui(string arg);
void create()
{
   set_name("岳山手卷", ({ "shou juan"}));
   set_weight(600);
   set("unit", "本");
   set("long","这是一本岳山手卷。\n");
set("no_give",1);
set("no_get",1);  
}

void init()
{
  add_action("do_linghui","linghui");
}

int do_linghui(string arg)
{
  object ob;
  
  ob=this_player();
  if(!arg||arg!="shou juan")
  return notify_fail("你要领会什么？\n");
  if(ob->query_skill("huanri-dafa",1)<100)
  return notify_fail("你从上面什么也领会不出来。\n");
  if(ob->query("eff_kee")*100/ob->query("max_kee")>20)
  return notify_fail("换日大法讲究“破而后立，败而后成”，你的方法似乎不对。\n");
  if(ob->query("gin")<100)
  return notify_fail("你的头脑有些昏沉，根本无法领会换日大法。\n");
  if(ob->query("potential")<30)
  return notify_fail("你的潜能不足以领会换日大法！\n");
  if(ob->is_busy()||ob->is_fighting())
  return notify_fail("你正忙着呢！\n");
  if(ob->query_skill("huanri-dafa",1)>=400)
  return notify_fail("你的换日大法已经登峰造极，无法再提高了！\n");
  ob->receive_damage("gin",100);
  ob->add("potential",-30);
  tell_object(ob,"你看着岳山手卷，气息回走五气、三脉、七轮,觉得换日大法有些进步了。\n");
  ob->start_busy(random(2));
  ob->improve_skill("huanri-dafa",ob->query("potential")*ob->query_int()/2);
  return 1;
}