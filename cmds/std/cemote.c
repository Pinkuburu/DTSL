//Cemote
//A very small bug let me expend very much time on it!
//Yanyan Fixed some small bugs.
#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        mapping emote;
        string *e;
    string result,msg;
    int i;int flag;
    flag=0;
    if( !arg )
        { 
                printf("此命令用于关键字查询semote  例如 cemote 鞠躬\n");
        }
    else 
        {me->add("gin",-20);
         
                e = EMOTE_D->query_all_emote();
                if(sizeof(e)<=0)
                return notify_fail("出现BUG[1]了，快去报告巫师，有GOLD发的！！\n");               
        
        result = "  序号    名称            内容\n" +
                                 "—————————————————————————————————————\n";
            for(i=0;i<sizeof(e);i++)
            {
                        emote=EMOTE_D->query_emote(e[i]);
                        if(!mapp(emote)){                       
                         break;}
            msg="";
            if(stringp(emote["others_target"]))
            msg=msg+emote["others_target"];
            if(strsrch(msg, arg) >=0)
            { 
                                result = result + sprintf("[%4d] %-13s: %s\n", i,e[i],msg);
                flag=1;
                continue;
                        }
            msg="";
            msg=msg+emote["others_self"];
            if(strsrch(msg, arg) >=0)
            {
                                result = result + sprintf("[%4d] %-13s: %s\n", i,e[i],msg);
                flag=1;
                continue;
            }
            msg="";
            msg=msg+emote["others"];
            if(strsrch(msg, arg) >=0)
            {
                                result = result + sprintf("[%4d] %-13s: %s\n", i,e[i],msg);
                flag=1;
                continue;
            }
        }
        if(!flag) result +="没有与您输入的关键字相匹配的emote.";
                result += "\n—————————————————————————————————————\n";
            me->start_more(result);
            return 1;
        }
    return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : cemote 关键字  列出目前所有含指定关键字的emote.

例如:
        cemote 倒霉
   序号    名称            内容
—————————————————————————————————————
[  42] :(           : $N愁眉苦脸的,一副倒霉样

—————————————————————————————————————

HELP
    );
    return 1;
}
