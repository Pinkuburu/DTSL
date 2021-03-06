
inherit NPC;

#include <ansi.h>
#include <job_money.h>

int test_player();
int cancel_me();
mapping tiename=([
RED"红铁矿"NOR:"hongtie",
YEL"橙铁矿"NOR:"chengtie",
HIY"黄铁矿"NOR:"huangtie",
GRN"绿铁矿"NOR:"lvtie",
HIC"青铁矿"NOR:"qingtie",
BLU"蓝铁矿"NOR:"lantie",
MAG"紫铁矿"NOR:"zitie",
//"红铁矿":"hongtie",
//"橙铁矿":"chengtie",
//"黄铁矿":"huangtie",
//"绿铁矿":"lvtie",
//"青铁矿":"qingtie",
//"蓝铁矿":"lantie",
//"紫铁矿":"zitie",
]);
void create()
{
  set_name("铁匠", ({ "tie jiang", "tie" }));
  set("age", 60);
  set("gender", "男性");
  set("long", "一个铁匠。\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
  set("combat_exp", 1200000);
  set("max_kee", 1500);
  set("max_sen", 1500);
  set("max_force", 1500);
  set("force", 1500);
  set("force_factor", 150);
  set_skill("unarmed", 90);
  set_skill("dodge", 60);
  set_skill("parry", 60);
  set_skill("force", 80);
  set("target_id","###");
  set("inquiry", ([
        "job":   (: test_player:),
        "放弃":   (: cancel_me:),
      ]));
  setup();

}

int test_player()
{
  string *strs = ({
    "$N对$n说道：  我现在想打点装备，需要",
    "$N想想说：我们这里现在急需",
  });  
  string str;
  object me = this_object();
  object who = this_player();
  string *n,*id1;int z;

if(who->query("combat_exp")>100000){
	   	
		command("hehe");
		command(
 		  "say 你的经验已经够高的了，去帮打铁工的忙吧！\n");
		return 1;
	    }

 

  if (who->query_temp("quest/tie"))
  {
    message_vision ("$N对$n说道：你不是答应帮我找"+who->query_temp("quest/tie/name")+"吗？怎么还没来？\n",me,who);
    return 1;
  }

if(time()-who->query("busy_time")<30){
	   	
		command("hehe");
		command(
 		  "say 我们这里暂时不缺东西，等会吧！\n");
		return 1;
	    } 
  n=keys(tiename);
  z=random(sizeof(n));  
/*
  if(z%2!=0) z++;
   if(z==sizeof(tiename)-1)
    z=z-2;  
*/
   id1=tiename[n[z]];
  who->set_temp("quest/tie/name", n[z]);
  who->set_temp("quest/tie/id", id1);
  who->set("busy_time",time()-20);
  str = strs[random(sizeof(strs))]+n[z]+
        "，\n这位"+RANK_D->query_respect(who)+
        "你去大巴山上帮我采点回来吧？\n";

  message_vision (str,me,who);
  return 1;
}

int cancel_me()
{	
	
	object target,me=this_player();

           if(!me->query_temp("quest/tie"))
	   
	{
	   command("bite");
	   command("say 我又没叫你帮我采矿，你放什么弃啊？！\n");
	   return 1;
       }
        JOBSYS_D->do_cancel_job("tiejiangjob1",me,this_object());
	
	command("say 没用的东西！！\n");
        return 1;
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


int accept_object(object who, object ob)
{
  object me = this_object();
  string name,jname,reason;
  int t;


  if (! who->query_temp("quest/tie"))
  {
    return notify_fail(query("name")+"对"+who->name()+"说道：我现在不缺这个，你给我也没用。\n");
   
  }

  if(ob->is_character()) return notify_fail("\n");
  
  name=no_color(ob->query("name"));
  jname=no_color(who->query_temp("quest/tie/name"));
  if (jname !=name)
  {
    return notify_fail(query("name")+"对"+who->name()+"说道：我叫你帮我采"+
		    who->query_temp("quest/tie/name")+
                    "，您却给我个"+ob->query("name")+"，这是什么意思？\n");
   
  }

  if (who->query_temp("quest/tie/id") != ob->query("id"))
  {
    return notify_fail(query("name")+"对"+who->name()+"说道：我等着您的"+who->query_temp("quest/tie/name")+
                    "，东西倒挺象，但不是同一个货；我要的是("+who->query_temp("quest/tie/id")+")，您给的是("+
                    ob->query("id")+")！\n");
  }
  
  reason = "帮我采到"+ob->query("name")+"，";
  message_vision ("$N对$n说道：你"+reason+"我真的要好好奖励你！\n",me,who);
  
  JOBSYS_D->give_reward_tiejiangjob1(who);
  who->delete_temp("quest/tie");
  who->set("busy_time",time());  
 
  return 1;
}
