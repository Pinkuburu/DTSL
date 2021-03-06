#include <ansi.h>
#include <mudlib.h>
inherit F_CLEAN_UP;

int level(mixed, mixed);
string wiz_rank(string hood);

int main(object me, string arg)
{
        string *list, hood = "", str;
        int j = 0;

        list = sort_array(SECURITY_D->query_wizlist(), (: level :) );
        str = HIC+CHINESE_MUD_NAME+NOR +"巫师成员：\n";
        str += "———————————————————\n";
        for(int i=0; i<sizeof(list); i++, j++) {
                if (hood!= wiz_rank(wizhood(list[i]))) {
                        hood = wiz_rank(wizhood(list[i]));
                        if (j%7) str += "\n";
                        str += hood;
                        str = replace_string(str,"(",HIG);
                        str = replace_string(str,")",": "NOR);
                        j = 0;
                }

                str += sprintf(" %s%s", list[i],
                        ( j%7==6 ) ? "\n" : ( i<sizeof(list)-1 && hood ==wizhood(list[i+1]) ) ? ", " : ""  );
        }
        str += "\n———————————————————\n";
        str += sprintf("目前一共有: %d个巫师\n",sizeof(list) );
        me->start_more(str);
        return 1;
}
string wiz_rank(string hood)
{	switch(hood) {
		case "(admin)":			
return HIG "【 天  帝 】" NOR;
		case "(honorary)":			
			return HIR "【名誉天帝】" NOR;
		case "(arch)":			
return HIR "【 大  神 】" NOR;
		case "(wizard)":		
return HIW "【 神  仙 】" NOR;
		case "(apprentice)":		
return HIY "【 仙  人 】" NOR;
		case "(immortal)":		
			return HIC "【 半  仙 】" NOR;
	}
}
int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob1) - wiz_level(ob2);
        return ob1 < ob2?-1:1;
}

int help(object me)
{
        write("\n指令格式 : wizlist\n"
        "用途 : 列出目前所有的巫师名单。\n"
        );
        return 1;
}
