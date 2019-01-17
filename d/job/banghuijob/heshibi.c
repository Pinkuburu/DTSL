#include <job_money.h>
#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(HIW"和氏璧"NOR, ({ "heshibi"}) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "玉石");
     set("unit", "块");
     set("value", 0);
   }
   setup();
}

int is_get_of(object me,object ob)
{
  object killer;
  if(ob->query("job/p_id")!=me->query("id"))
  return notify_fail("这样东西你拿不起来！\n");
  message_vision(HIW"$N只听啪地一声，和氏璧炸成了碎片！\n",me);
  killer=new(__DIR__"killer");
  copy_object(killer,me);
  killer->set("job/p_id",me->query("id"));
  killer->set_name("蒙面人",({"man"}));
  killer->delete("family");
  killer->delete("nickname");
  killer->delete("title");
  killer->move(environment(me));
  message_vision(HIR"$N冷笑道：我就是放了个假和氏璧来引你们宋家堡的人上钩，没想到还真来了！\n"NOR,killer);
  killer->kill_ob(me);
  ob->set("name","碎掉的和氏璧");
  return 1;
}
  
