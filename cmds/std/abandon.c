// abandon.c

#include <ansi.h>
inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
        int level, exp1,lvl = 0;string skill_type,*type_class;int flag,skill_flag;
        flag=0,skill_flag=0;
        if( !arg ||sscanf(arg, "%s %d", arg, lvl)!=2) return notify_fail("指令格式：abandon|fangqi <技能名称|原有EXP> [级数]|<保留EXP>\n");
                
          if(arg=="exp") {
          exp1=me->query("combat_exp");
//         if (!intp(lvl)) return notify_fail("指令输入错误，请检查。\n");
          if(lvl<0||lvl>exp1) {
           write("\nexp不能放弃到小于零或者大于你本身原有的exp!\n");
          return 1;
         }
             write(HIY"您选择放弃exp到"+lvl+"，请务必\n"
        "考虑清楚，放弃的话你的exp将为"HIR BLINK+chinese_number(lvl)+NOR HIY"，确定的话请输入您的密码："NOR);
    input_to("check_password", 1, me, 1,lvl);
       return 1;
       }
        level = me->query_skill(arg, 1);
       
        if (!intp(lvl) || lvl < 0) 
                return notify_fail("级数不可为负数。\n");
        if(!me->query_skill(arg,1))
        return notify_fail("你没有学会这个技能！\n");
 if(arg=="sashoufa") {
     if(me->query_skill(arg,1))
    return notify_fail("这个技能不能放弃！\n");
  return 1;
    }
 if(arg=="siguanfa") {
     if(me->query_skill(arg,1))
    return notify_fail("这个技能不能放弃！\n");
  return 1;
    }
        if (lvl <= 0 || lvl >= level) {
                write("\n注意！你将要放弃全部 "HIW + to_chinese(arg) + "("+arg+")"NOR" ，确定吗？[Y|N]\n>");
                input_to("delete_all", me, arg);
                                
                                return 1;
                } 
        else if (level < 100)
                return notify_fail("你这项技能还没有到能收放自如的地步。\n");
        else {
                write("\n注意！你将要放弃" + chinese_number(lvl)+ "级 "HIW+to_chinese(arg)+"("+arg+")"NOR" ，确定吗？[Y|N]\n>");
                input_to("delete_skill", me, arg, level, lvl);
                }
        return 1;
   
}

private void delete_all(string arg, object me, string skill)
{   string skill_type;int flag,skill_flag;
        flag=0;
        
                skill_type=SKILL_D(skill)->query_type();
                if(skill_type!="base"&&skill_type!="knowledge")
                        flag=1;
        if( arg[0]=='y' || arg[0]=='Y' ){
                me->delete_skill(skill);
                if(userp(me) && !wizardp(me))
                     log_file("ABANDON", sprintf("%s(%s)  abandoned ALL  %s  on %s\n",
                          me->name(1),me->query("id"), to_chinese(skill) , ctime(time()) ));
                write("你放弃了"+ to_chinese(skill) +"。\n\n");
                                if(flag)
                                me->reduce_array(skill_type,skill);
                               if(me->query(skill_type)==({}))
                                me->delete(skill_type); 
                                
                }
        else write("你决定保留"+ to_chinese(skill) +"("+skill+")。\n\n");
        
}

private void delete_skill(string arg, object me, string skill, int level, int lvl)
{
        if( arg[0]=='y' || arg[0]=='Y' ){
                me->set_skill(skill, level - lvl);
                if(userp(me) && !wizardp(me))
                     log_file("ABANDON", sprintf("%s(%s)  abandoned  %d levels of %s  on %s\n",
                          me->name(1),me->query("id"), lvl, to_chinese(skill) , ctime(time()) ));
                write("你放弃了" + chinese_number(lvl)+ "级"+ to_chinese(skill) +"("+skill+")。\n\n");
                }
        else write("你决定保留"+ to_chinese(skill) +"("+skill+")。\n\n");
        
}

private void check_password(string passwd, object me, int forever,int lvl)
{
    object link_ob;
    string old_pass;

    if (!link_ob = me->query_temp("link_ob"))
    {
    write(HIR "档案形成不完全，请quit后重新进入。\n"NOR);
    return;
    }
    if (!link_ob->query("password"))
    {
    write(HIR "档案形成不完全，请quit后重新进入。\n"NOR);
    return;
    }
    old_pass = link_ob->query("password");
    if (!stringp(old_pass) || crypt(passwd, old_pass) != old_pass)
    {
        write(HIR "密码错误！请注意，放弃exp必须输入密码。\n"NOR);
        return;
    }

    if (forever)
    {
        tell_object(me, HIR BLINK"\n你决定将exp放弃到"+chinese_number(lvl)+"!\n\n" NOR);
        me->set("combat_exp",lvl);
    }
}

int help()
{
        write("
指令格式：abandon|fangqi <技能名称|原有exp> [级数]|<保留exp>

放弃一项你所学过的技能，注意这里所说的「放弃」是指将这项技能从你人物
的资料中删除，如果你以后还要练，必须从０开始重练，请务必考虑清楚。

或者可以选择放弃指定的级数，范围必须是 1 到现有级数之间的数目，大于级
数意味着全部放弃！

这个指令使用的场合通常是用来删除一些「不小心」练出来的技能，由于每个
人有着不同的天赋，所修习的武功也不会相同。如果样样都学，到头来只会样
样不精。

例： abandon exp 100.       放弃经验到100。
例： abandon dodge 10.      放弃 10 级基本轻功。
     abandon dodge.         放弃基本轻功。
     

注意：巫师不会恢复你放弃的武功，一切后果自负！
     
\n");
        return 1;
}

