
#include <ansi.h>
inherit SSERVER;
/*心法执行函数
  统一放在 /daemon/skill/exec/ 下。
*/
int execute(object me,object victim)
{
  
  int max_points,cost_force,lev;
  string msg;
  int time,add_time;
  
  if(victim!=me)
  return notify_fail("你不能对别人使用这个心法。\n");
  
  if(me->query_skill("huachan",1))
  return notify_fail("你学了画禅，无法施展顽石诀！\n");
  
  if(me->query("force")<=0)
  return notify_fail("你的内力不足！\n");
  
  max_points=me->query("max_apply_points")-me->query("apply_points");
  if(max_points<=0)
  return notify_fail("你现在气势高涨，无须用心法催加。\n");
  if(time()-me->query_temp("execute_busy")<10)
  return notify_fail("你不能连续使用心法。\n");
  
  lev=me->query_skill("wanshi-jue",1);
  cost_force=max_points*3*(100+lev)/(2*lev);
  if(cost_force<=0)
   cost_force=max_points;
  
  if(me->query("force")<cost_force){
    cost_force=me->query("force");
    max_points=max_points/2;
  }
  
  msg=HIB"$N"+HIB+"低头微喝一声，抬起头来，已是双目炯炯有神，气势迫人！\n"NOR;
  message_vision(msg,me);
  
  //缓慢增加气势：
  
  add_time=3;
  me->set_temp("add_apply_points",max_points/add_time);
  me->set_temp("reduce_force",cost_force/add_time);
  me->set_temp("add_apply_points_yushu",max_points%add_time);
  me->set_temp("reduce_force_yushu",cost_force%add_time);
  me->set_temp("add_apply_points_times",add_time);
  
  //心法持续时间：
  time=3*lev/(lev+100);
  if(time<=0)
  time=1;
  me->set("apply_points_last",time);
  me->set("apply_points_reduce",(max_points+me->query("apply_points"))/6);
  me->set("apply_points_last_times",time);
  
  //心法满了后持续的时间：
  
  me->set("full_points_last",1);
  me->set_temp("execute_busy",time());
  
  return 1;
}