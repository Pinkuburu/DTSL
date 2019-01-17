// makelove.c

#include <ansi.h>
#include <login.h>
inherit F_CLEAN_UP;
object make_body(object ob);
int check_legal_id(string id);
int check_legal_name(string name);
string *banned_name=({});
int main(object me, string arg)
{
        object who;
        string target;

        if(me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着呢，怎样makelove呀？\n");

        if(!arg ) return notify_fail("指令格式：makelove with　＜某人＞\n");

        if ( sscanf( arg, "with %s", target ) != 1 ) 
                return notify_fail("指令格式：makelove with　＜某人＞\n");
        if ( target!= me->query("couple/couple_id") )
                return notify_fail("只有夫妻之间才能作爱！\n");

        if( !(who=present(target,environment(me))) )
                return notify_fail("你的配偶不在这里啊！\n"); 
        if ( ( me->query("gin") < me->query("max_gin")/2 )||
             ( me->query("kee") < me->query("max_kee")/2 ) )
                return notify_fail("你目前的身体状况太差了，再要作爱只怕有生命危险！\n");

        if ( ( who->query("gin") < who->query("max_gin")/2 )||
             ( who->query("kee") < who->query("max_kee")/2 ) )
                return notify_fail(who->name()+"目前的身体状况太差了，再要作爱只怕有生命危险！\n");

        // start making love between these two people :P
        me->start_busy(7);
        who->start_busy(7);
        me->set_temp("apply/short",({HIY"闲人免看"NOR}));
        who->set_temp("apply/short",({HIY"闲人免看"NOR}));
        environment(me)->set("makelove_room",1);
        if(me->query("gender") == "女性" ) 
            message_vision(CYN"$N依偎在$n的怀里，眼中含情脉脉，脸上娇羞无限．\n"+
                "$n拥抱着$N，给了$N一个深深的吻！\n"NOR,me,who);
        else 
            message_vision(CYN"$n拥抱着$N，给了$N一个深深的吻！\n"+
                "$N依偎在$n的怀里，眼中含情脉脉，脸上娇羞无限．\n"NOR,who,me);

        call_out("step2",2,me,who);
        return 1;
}

int step2(object me, object who)
{
        if(me->query("gender") == "男性" ) 
            message_vision(YEL"$N紧紧地抱住$n，两个人的心在一起跳动，感情在一起升温！！\n"NOR,me,who);
        else
            message_vision(YEL"$N紧紧地抱住$n，两个人的心在一起跳动，感情在一起升温！！\n"NOR,who,me);

        call_out("remove_cloth",1,me);
        call_out("remove_cloth",1,who);
        call_out("step3",3,me,who);
        return 1;
}

int step3(object me, object who)
{
        message_vision(MAG"$N和$n沉浸在幸福的海洋里＃＠＃％＆＆＊＆％￥＃\n"NOR,me,who);
        call_out("step4",2,me,who);
        return 1;
}

int step4(object me, object who)
{
        if(me->query_condition("xxx"))
                me->clear_condition("xxx");
        if(who->query_condition("xxx"))
                who->clear_condition("xxx");

        me->receive_damage("gin",me->query("max_gin")/2);
        me->receive_damage("kee",me->query("max_kee")/2);

        who->receive_damage("gin",who->query("max_gin")/2);
        who->receive_damage("kee",who->query("max_kee")/2);
        me->delete_temp("apply");
        who->delete_temp("apply");
        if(me->query("gender")=="女性"&&!me->query("have_baby"))
        me->add("makelove_times",1);
        else
        if(!who->query("have_baby")) 
        who->add("makelove_times",1);
        message_vision(HIW"终于一切又恢复了平静．\n"NOR,me,who);
        environment(me)->delete("makelove_room");
       /* if(me->query("gender")=="女性"&&me->query("makelove_times")>=40)
        {
        	message_vision("$N忽然觉得腹中一阵疼痛!\n",me);
        	me->delete("makelove_times");
        	call_out("birth",1,who,me);
        }
        if(who->query("gender")=="女性"&&who->query("makelove_times")>=40)
        {
        	message_vision("$N忽然觉得腹中一阵疼痛!\n",who);
        	who->delete("makelove_times");
        	call_out("birth",1,me,who);
        }*/
        return 1;
}

int remove_cloth(object me)
{
        object *inv;
        string str;
        int i;
        // remove all staff before sleepping :P
        inv = all_inventory(me);
        for(i=0; i < sizeof(inv); i++ ) {
            if( inv[i]->query("equipped") == "worn" ) {
                if( inv[i]->unequip() ) {
                    if( !stringp(str = inv[i]->query("remove_msg")) )
                        switch(inv[i]->query("armor_type")) {
                                case "cloth":
                                case "armor":
                                case "surcoat":
                                case "boots":
                                        str = YEL "$N将$n脱了下来。\n" NOR;
                                        break;
                                case "bandage":
                                        str = YEL "$N将$n从伤口处拆了下来。\n" NOR;
                                        break;
                                default:
                                        str = YEL "$N卸除$n的装备。\n" NOR;
                        }
                message_vision(str, me, inv[i]);
                }
            } else if ( inv[i]->query("equipped") == "wielded" ) {
                if(inv[i]->unequip() ) {
                    if( !stringp(str = inv[i]->query("unwield_msg") )) 
                        str = YEL "$N放下手中的$n。\n" NOR;
                message_vision(str, me, inv[i]);
                }
            }
        }
}

void birth(object me,object ob)
{
   "/adm/daemons/marryd.c"->do_birth(me,ob);
   return;
}

int help(object me)
{
  write(@HELP
指令格式 : makelove with <配偶>
 
这个指令让你与你的配偶作爱．
 
HELP
    );
    return 1;
}
 
