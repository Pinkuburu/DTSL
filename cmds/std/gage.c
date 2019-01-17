//for dtsl.
#include <ansi.h>
#include <org.h>
inherit F_CLEAN_UP;


int main(object me, string arg)
{
   object ob;
   if(!arg) return notify_fail("你想向谁挑战？\n");
   if(!objectp(ob=present(arg,environment(me))))
    return notify_fail("这里没有这个人。\n");
   if(me->query("shili/name")!=ob->query("shili/name"))
    return notify_fail("你们势力不同，还是fight吧!\n");
   if(!userp(ob)&&!ORG_D->is_leader(ob->query("shili_id")))
    return notify_fail(ob->name()+"笑笑，我不是首领，你向我挑战什么啊？\n");
   if(!userp(ob)&&ob->query("shili/leader"))
   {  me->set_temp("gage",ob);
      ob->set_temp("gage",me);
      message_vision("$N一笑道：既然是来挑战首领之位，指教了！！\n",ob);
      return (int)ob->accept_gage(me);
    }
    
    if(ob->query_temp("gage")==me)
    { message_vision("$N一抱拳：指教了！\n",me);
      me->set_temp("gage",ob);
      me->fight_ob(ob);
      return 1;
     }
    if(userp(ob)&&!ob->query("shili/leader"))
    return notify_fail("他不是势力的首领，你还是fight吧!\n");
    me->set_temp("gage",ob);
    tell_object(ob,me->name()+"要向你挑战，如果接受，请使用gage命令。\n");
    tell_object(me,"你向"+ob->name()+"挑战，请等待回应。\n");  
   return 1;
}
