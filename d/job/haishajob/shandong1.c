
#include <ansi.h>
#include <job_money.h>
inherit ROOM;


void create ()
{
  set ("short",HIB"山洞"NOR);
  set ("long", @LONG
这里是一个山洞，黑黑的，几乎看不到有什么出路。据说最近这里
来了很多抢宝藏的人，你不禁小心起来。
LONG);

  set("exits", ([ 
 "enter":__DIR__"shandong2",
 "out":"/d/taishan/nantianmen",
        ]));
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object ob,string dir)
{
  object killer;
  object *targets;
  int i;
  if(ob->query("job/duobao_job")&&!ob->query("job/flag1"))
  {
    ob->set("job/flag1",1);
    killer=new(__DIR__"killer"+(1+random(6)));
    killer->move(environment(ob));
    killer->set("combat_exp",ob->query("combat_exp"));
    if("/cmds/usr/hp.c"->get_pot(killer));
    set_all_skill(killer,ob->query("max_pot")-80);
    killer->set("target_id",ob->query("id"));
    killer->kill_ob(ob);
    ob->kill_ob(killer);
    return notify_fail("猛然跳出一个人，冷笑道：既然来了，就别走了！\n");
   }
  if(ob->query("job/duobao_job")){
   targets=all_inventory(environment(ob));
   for(i=0;i<sizeof(targets);i++)
   if(targets[i]->query("target_id")==ob->query("id")&&
      targets[i]!=ob)
   return notify_fail("杀手一把抓住了你！\n");}
   
  return ::valid_leave(ob,dir);
}