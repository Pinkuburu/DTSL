//job.
// 帮会任务系统。
#include <job_money.h>
#include <ansi.h>
inherit NPC;
#include "/d/job/banghuijob/map.h"
string give_job();
void create()
{
   set_name("军官",({ "jun guan","jun","guan" }) );
        set("gender", "男性" );
        set("title","李阀军官");
        set("nickname",HIR"杀绝李阀叛徒"NOR);
        set("age", 32);
   set("long", "这是李阀的军官，专门处理叛徒。\n");
   set("combat_exp", 500000);
   set("str", 30);
   set("inquiry",([
     "job":(:give_job:),
     ]));
   setup();
   
}

string give_job()
{
  object me,ob,killer;string *dir,jobdir;int i;
  me=this_player();
  ob=this_object();
  if(me->query("shili/name")!="lifa_b")
  return "只有李阀的人能做这个任务！\n";
  if(me->query("combat_exp")<100000)
  return "你的武功太低微了，等你厉害了再来吧！\n";
  if(me->query_temp("bhjob/lifa"))
  return "我可不喜欢马马乎乎的人！\n";
  if(time()-me->query("busy_time")<90)
  return "你还是歇会吧！\n";
  dir=keys(map);
  i=random(sizeof(dir));
  jobdir=dir[i];
  killer=new(__DIR__"pantu");
  copy_object(killer,me);
  killer->set("job/p_id",me->query("id"));
  killer->delete("family");
  killer->delete("nickname");
  killer->delete("title");
  killer->set("nickname",HIR"李阀叛徒"NOR);
  killer->set_name("叛徒",({"pan tu","pan","tu"}));
  killer->move(jobdir);
  tell_object(environment(killer),"一阵大风吹过，一个蒙面人飘然而落！\n");
  me->set_temp("bhjob/lifa",1);
  return "我们李阀最近出了叛徒，据说在"+map[jobdir]+",你去把他杀了！\n";
}
