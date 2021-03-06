
#include <ansi.h>
#include <condition.h>
#include <job_money.h>
inherit F_CLEAN_UP;

int update_condition(object me, int times)
{
   if(times<=0){   
  if(!me->query_temp("job/rong_job"))
  return 0;
  call_out("killer_come",1,me);
  return 0;}
   me->apply_condition("rongsx",times-1);
   return CND_CONTINUE;
}

void killer_come(object ob)
{
  object killer,letter;
  string kill_msg;
  if(!objectp(ob)){
  remove_call_out("killer_come");return;}
  kill_msg="$N朝$n喝道：我和荣凤祥是仇敌，你敢为他办事，拿命来！\n";
  killer=new("/d/job/songwupin/killer");
  ob->start_busy(1);
  message_vision(HIB"$N突然觉得一阵冷风吹来！"NOR,ob);
  copy_object(killer,ob);
  killer->set_name("杀手",({"killer"}));
  killer->set("nickname",HIR"冷血无情"NOR);
  killer->delete("family");
  killer->delete("nickname");
  killer->delete("shili");
  killer->set("combat_exp",ob->query("combat_exp")*3/2);
  killer->move(environment(ob));
  message_vision(kill_msg,killer,ob);
  killer->set_leader(ob);
  killer->kill_ob(ob);
  remove_call_out("killer_come");return;
}
