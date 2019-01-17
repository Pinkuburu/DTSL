
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
  
  if(me->query("force")<=0)
  return notify_fail("你的内力不足！\n");
  
  max_points=me->query("max_apply_points")-me->query("apply_points");
  if(max_points<=0)
  return notify_fail("你现在气势高涨，无须用心法催加。\n");
  
  if(time()-me->query_temp("execute_busy")<5)
  return notify_fail("你不能连续使用心法。\n");
  
  lev=me->query_skill("tianmo-jue",1);
  cost_force=max_points*3*(100+lev)/(2*lev);
  if(cost_force<=0)
   cost_force=max_points;
  
  if(me->query("force")<cost_force){
    cost_force=me->query("force");
    max_points=cost_force/2;
  }
  
  msg=HIR"$N"+HIR+"突然双目一睁，顿时气势迫人！\n"NOR;
  message_vision(msg,me);
  //me->add("force",-cost_force);
  //me->add("apply_points",max_points);
  
  //缓慢增加气势：
  
  add_time=5;
  me->set_temp("add_apply_points",max_points/add_time);
  me->set_temp("reduce_force",cost_force/add_time);
  me->set_temp("add_apply_points_yushu",max_points%add_time);
  me->set_temp("reduce_force_yushu",cost_force%add_time);
  me->set_temp("add_apply_points_times",add_time);
  
  //心法持续时间：
  time=5*lev/(lev+100);
  if(time<=0)
  time=1;
  me->set("apply_points_last",time);
  me->set("apply_points_reduce",(max_points+me->query("apply_points"))/6);
  me->set("apply_points_last_times",time);
  
  //心法满了后持续的时间：
  
  me->set("full_points_last",3);
  me->set_temp("execute_busy",time());
  
  return 1;
}