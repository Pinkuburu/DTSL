//by lanxin 98-11-25
//Mdified by yanyan.for dt.
//add family and banghui.
// who.c

#include <net/dns.h>
#include <ansi.h>
#include <org.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }
int sort_user(object,object);
string left(string str,int long);
string query_guanzhi(object ob)
{
  return ORG_D->query_short_guanzhi(ob);
}
string query_nick(object ob)
{
  if(!ob->query("nickname")) return "";
  return "「"+ob->query("nickname")+"」";
}
mixed main(object me, string arg, int remote)
{
        string str, *option,now;object ob;
        object *list;string fname;
        int i, j, ppl_cnt;int wcnt,mcnt;
        int opt_long, opt_id, opt_wiz;
        int opt_party,opt_org;int cnt,unt,idnt;
        wcnt=0,mcnt=0;fname="";cnt=0;unt=0;idnt=0;
        if( arg ) {
                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- )
                        switch(option[i]) {
                                case "-l": opt_long = 1;        break;
                                case "-i": opt_id = 1;          break;
                                case "-w": opt_wiz = 1;         break;
                                case "-p": opt_party=1;         break;
                                case "-b": opt_org=1;         break;
                                default:
                                        if(option[i][0]=='@')
                                        {
                                                RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],
                                                        me, opt_long);
                                                write("网路讯息已送出，请稍候。\n");
                                                return 1;
                                        }
                                        return notify_fail("指令格式：who [-l|-i|-w|-b]\n");
                        }
        }

        if( opt_long ) {
		
if( (int)me->query("gin")<10)
                        return notify_fail("你的精神太差了，没有办法得知其他玩家的详细资料。\n");
		me->receive_damage("gin",10);
        }

        str = HIY"◎ " + "大唐双龙 ◎" NOR+ "\n";
        if(me->query("shili/name")&&opt_org) str+=HIW"目前与你同一势力的在线人员：\n"NOR;
        if(!me->query("shili/name")&&opt_org) str+=HIW"目前没有加入势力的在线人员：\n"NOR;
        str += HIG"—————————————————————————————————————\n"NOR;
//      list = users();
ob = filter_array(objects(), (: userp :));
	if (opt_party)
		ob = filter_array(ob, (: $1->query("family/family_name") ==
			$2->query("family/family_name") :), me);
	if (opt_org)
		ob = filter_array(ob, (: $1->query("shili/name") ==
			$2->query("shili/name") :), me);
list = sort_array(ob, (: sort_user :));
        if( opt_long || opt_wiz ) {
                j = sizeof(list);
                while( j-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                        if( !interactive(list[j]) ) continue;
                        if( !me->visible(list[j]) ) continue;
                        if( opt_wiz && !wizardp(list[j]) ) continue;
                        if (interactive(list[j])) unt++;
			else cnt++;
                        if( list[j]->query_temp("netdead")) now=HIW"断"NOR;
			else    if(query_idle(list[j])>180)
                                        {now=HIY"呆"NOR;idnt++;}
                                else now=HIR"√"NOR;
                        if(list[j]->query("shili")){
			str = sprintf("%s%12s%s "+HIC+"%s"+NOR+HIR+"%s"+NOR+" %s %s"+"（%s）\n",
			str,RANK_D->query_rank(list[j]),now,
                        "/cmds/usr/score.c"->get_shili(list[j]),
                        query_guanzhi(list[j]),query_nick(list[j]),
                        list[j]->name(),list[j]->query("id")
                        );} else {
                        str = sprintf("%s%12s%s %s\n",
			str,RANK_D->query_rank(list[j]),now,
                                list[j]->short(1)
                        );}
                }
        } else {
                ppl_cnt = 0;
                j = sizeof(list);
                while( j-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[j]) ) continue;
                        if( me && !me->visible(list[j]) ) continue;
                        if( list[j]->query_temp("netdead")) now=HIW"断"NOR;
                        else    if(query_idle(list[j])>180)
                                        {now=HIY"呆"NOR;idnt++;}
                                else now="";
                        if(!wizardp(list[j])
                        &&fname!=list[j]->query("family/family_name")){
                        /*if( ppl_cnt%5 )*/ str += "\n";
                        fname=list[j]->query("family/family_name");
                        str += sprintf(HIY "%-10s" NOR, (fname?fname:"普通百姓") + "：");
                          ppl_cnt=1;
                              }
                        if(wizardp(list[j])&&!wcnt){
                           /*if( ppl_cnt%5 )*/ str += "\n";
                           str += sprintf(HIY "%-10s" NOR, "巫师：");
                           wcnt=1;
                           ppl_cnt=1;
                        }
                        if (!(ppl_cnt%5)) {
				ppl_cnt++;
				str +=sprintf("%-10s","");
			}
                        str += left(sprintf("%s%-10s"NOR,
                                now,
                                opt_id ? list[j]->name(1) +"("+capitalize(list[j]->query("id"))+")": list[j]->name(1) ),18); 
                        if(ppl_cnt%4==0){
                        	str+="\n";
                        	ppl_cnt=0;}
                        else ppl_cnt++;
                        if (interactive(list[j])) unt++;
			else cnt++;
                }
                if( ppl_cnt%5 ) str += "\n";
        }
                
        str += HIG"—————————————————————————————————————\n"NOR;
        str += HIY"呆"NOR+":发呆中      "+HIW"断"NOR+":断线中.\n";
        str = sprintf("%s共有 %d 位使用者连线中，%d位断线中，%d位发呆中。\n系统负担：%s\n", str, unt,cnt,idnt,
                query_load_average() + "\n");

        if( remote ) return str;

        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        string name1, name2;

	reset_eval_cost();
	if( wiz_level(ob1) != wiz_level(ob2) )
		return wiz_level(ob2)
			- wiz_level(ob1);
	
	name1 = ob1->query("family/family_name");
	name2 = ob2->query("family/family_name");

	if (intp(name1)) name1 = "";
	if (intp(name2)) name2 = "";
	if (name1 > name2) return -1;
	if (name1 < name2) return 1;

	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}
string no_color(string arg)
{
        arg = replace_string(arg,  BLK, "");
	arg = replace_string(arg,  RED, "");
	arg = replace_string(arg,  GRN, "");
	arg = replace_string(arg,  YEL, "");
	arg = replace_string(arg,  BLU, "");
	arg = replace_string(arg,  MAG, "");
	arg = replace_string(arg,  CYN, "");
	arg = replace_string(arg,  WHT, "");
	arg = replace_string(arg,  HIR, "");
	arg = replace_string(arg,  HIG, "");
	arg = replace_string(arg,  HIY, "");
	arg = replace_string(arg,  HIB, "");
	arg = replace_string(arg,  HIM, "");
	arg = replace_string(arg,  HIC, "");
	arg = replace_string(arg,  HIW, "");
	arg = replace_string(arg,  NOR, "");
	arg = replace_string(arg,  BLINK, "");
	return arg;
}

string left(string str,int long)
{
	int space,len,i;
	string s,oldstr;
	s="";oldstr=str;
	str=no_color(str);
	len=strlen(str);
	space=(long-len);
	for(i=0;i<space;i++) s+=" ";
	return sprintf("%s%s",oldstr,s);
}

int help(object me)
{
write(@HELP
指令格式 : who [-l|-i|-w|-b]

这个指令可以列出所有在线上的玩家及其等级。

-l 选项列出较长的讯息。
-i 只列出玩家的英文代号。
-w 只列出线上所有的巫师。
-p 只列出与你相同门派的玩家
-b 只列出与你相同势力的玩家

相关指令： finger
HELP
    );
    return 1;
}
