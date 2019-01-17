#include <ansi.h>
inherit ITEM;
mapping name=([
"清心诀":"qingxinjue","般若经":"banruojing","法华经":"fahuajing",
"金刚经":"jingangjing","无量经":"wuliangjing","普善经":"pushanjing",
"大无相经":"dawuxiangjing","小无相经":"xiaowuxiangjing",
"静禅经":"jingchanjing",
]);
int do_chao(string arg);
void create()
{
   string *na;int i;
   na=keys(name);
   i=random(sizeof(na));
   
   set_name(na[i], ({name[na[i]]}) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
     set("unit", "本");
     set("value", 0);
     set("no_drop",1);
     set("no_get",1);
   }
   setup();
}
int is_get_of(object pa,object ob)
{
  return notify_fail("这个东西你拣不起来！\n");
}

void init()
{
  add_action("do_chao","chao");
}

int do_chao(string arg)
{
  object me,ob;
  me=this_player();
  if(!arg)
  return notify_fail("你要抄什么经书？\n");
  ob=present(arg,me);
  if(!ob)
  return notify_fail("你身上没有这个东西！\n");
  if(ob!=this_object())
  return notify_fail("这个东西怎么用来抄经书啊！\n");
  if(me->query("gin")<me->query_skill("wuwang-jing",1)/5+me->query_int()/4)
  return notify_fail("你发现精神十分疲劳，无法继续抄下去！\n");
  if(me->query_temp("cihang-job-ok"))
  return notify_fail("你已经完成任务了！\n");
  if(me->query_temp("cihang-job")!=base_name(environment(me)))
  return notify_fail("你走错地方了！\n");
  message_vision("$N拿起笔来，一丝不苟地将经书抄在纸上。\n",me);
  me->receive_damage("gin",me->query_skill("wuwang-jing",1)/5+me->query_int()/4);
  me->add_temp("cihang-job-times",1);
  if(me->query_temp("cihang-job-times")>random(3)+8){
  message_vision(YEL"$N长嘘了口气，终于抄完了一部分，可以回去向秦云明交差了！\n"NOR,me);
  me->set_temp("cihang-job-ok",1);
  this_object()->set_temp("cihang-job-ok",1);
  return 1;}
  me->start_busy(2);
  return 1;
}