//job.
// 帮会任务系统。
#include <job_money.h>
#include <ansi.h>
inherit NPC;
#include "/d/job/banghuijob/map.h"
string give_job();
void create()
{
   set_name("宋雨",({ "song yu","song","yu" }) );
        set("gender", "男性" );
       set("age", 32);
   set("long", "这是宋家堡的宋雨。\n");
   set("combat_exp", 500000);
   set("str", 30);
   set("inquiry",([
     "job":(:give_job:),
     ]));
   setup();
   
}

string give_job()
{
  object me,ob,thing;string *dir,jobdir;int i;
  me=this_player();
  ob=this_object();
  if(me->query("shili/name")!="songjia_b")
  return "只有宋家堡的人能做这个任务！\n";
  if(me->query("combat_exp")<100000)
  return "你的武功太低微了，等你厉害了再来吧！\n";
  if(me->query_temp("bhjob/songjia"))
  return "我可不喜欢马马乎乎的人！\n";
  if(time()-me->query("busy_time")<90)
  return "你还是歇会吧！\n";
  dir=keys(map);
  i=random(sizeof(dir));
  jobdir=dir[i];
  thing=new(__DIR__"heshibi");
  thing->set("job/p_id",me->query("id"));
  thing->move(jobdir);
  me->set_temp("bhjob/songjia",1);
  return "我们宋家堡要争天下必须找到[和氏璧]，据弟子说在"+map[jobdir]+",你去找找！\n";
}
