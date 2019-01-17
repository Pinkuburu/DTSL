
// propose.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object who;
   string *wives;
   mapping wiv;

        if(me->query("age")<21)
   return notify_fail("你年龄太小了，等等吧！\n");    
   
        if (!arg) return notify_fail("你要向谁求婚？\n");

        if (me->query("gender")=="女性")
                return notify_fail("只有男人才能向别人求婚！\n");

        if (!objectp(who=present(arg,environment(me))))
                return notify_fail("这里没有这个人。\n");

        if (!who->is_character())
                return notify_fail("想清楚！"+who->name()+"是什么呀！\n");

        if (who==me)
                return notify_fail("开什么玩笑？！？\n");
        if(me->query("couple/couple_id")==who->query("id"))
        return notify_fail("你一挠头：哦，她已经是我的妻子了！\n");
        if (me->query("couple"))
                return notify_fail("嘿嘿，不怕" + me->query("couple/couple_name") + "揍你吗？\n");

        if (!living(who))
                return notify_fail("嗯...你还是先把"+who->name()+"弄醒吧。\n");

        if (who->query("gender")=="男性")
                return notify_fail("嗯？你变态吗？！？\n");

if ((me->query("class")=="bonze")||(who->query("class")=="bonze"))
return notify_fail("出家人四大皆空，婚嫁之事就免了吧。\n");

        if (who->query("couple"))
                return notify_fail("还是算了吧，"+who->name()+"是有夫之妇啦！\n");
        if(me->query("env/marry_msg"))
        message_vision("$N对$n温柔地说道："+me->query("env/marry_msg")+"\n", me, who);
        else message_vision("$N对$n温柔地说道：我很喜欢你，嫁给我好吗？\n", me, who);
        me->set("proposing",1);
        me->set("propose_target", getuid(who));
        who->set("proposed",1);
        who->set("propose_man", getuid(me));

        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : propose <某人>
 

HELP);
    return 1;
}

