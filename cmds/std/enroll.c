//for dtsl.
#include <ansi.h>
#include <org.h>
inherit F_CLEAN_UP;


int main(object me, string arg)
{
   object ob;
   
   if(!arg) return notify_fail("你想加入谁的势力？\n");
   if(!objectp(ob=present(arg,environment(me))))
    return notify_fail("这里没有这个人。\n");
   if(me->query("shili")&&ob->query("shili")&&
      me->query("shili/name")==ob->query("shili/name"))
   return notify_fail("你们已经是一个帮会的人了！\n");
   if(me->query("shili"))
   return notify_fail("你如果要加入新的帮会必须退出原来的帮会！\n");
   if(!userp(ob)&&!ORG_D->is_leader(ob->query("shili_id")))
    return notify_fail(ob->name()+"笑笑：我不是首领，你和我说没用的。\n");
   if(!userp(ob))
     if(!ob->accept_enroll(me))
       return ob->accept_enroll(me);
       //return notify_fail(ob->name()+"不打算让你加入他的势力\n");
     else return 1;
   if(!ob->query("shili/leader"))
     return notify_fail("他不是势力的首领，你和他说没用的！\n");
   ob->set_temp("mark_join",me->name());
   tell_object(ob,HIY+me->name()+"想加入你们的势力，如果愿意的话，请用 adopt 接受他的加入\n"NOR);
   tell_object(me,HIY"你想加入"+ob->name()+"的势力，请等待他的回应\n"NOR);
   return 1;
}
