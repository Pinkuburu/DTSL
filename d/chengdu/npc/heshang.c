
inherit NPC;
#include <ansi.h>
#include <job_money.h>
mapping *ask=({
([
 "ask":HIW"菩提本非树,明镜亦非台"NOR,
 "answer":"本来无一物,何处惹尘埃",
 ]),
 ([
 "ask":HIW"何名坐禅？"NOR,
 "answer":"内见自性不动，名为禅",
 ]),
 ([
 "ask":HIW"何名禅定？"NOR,
 "answer":"外禅内定，是为禅定",
 ])
});
string ask_quest();
int do_answer(string arg);
void create()
{
       set_name("和尚", ({ "he shang","he","shang"}) );
       set("gender", "男性" );
       set("age", 30);
       set("long","这是这家寺庙的和尚,现在只有他还在这里信守佛法。\n");
       set("combat_exp", 12500);
       set("attitude", "friendly");
       set("class","bonze");
	   set("inquiry",([
		   "讲经":(:ask_quest:),
		   ]));
       setup();
 carry_object(__DIR__"obj/sengyi")->wear();


}

void init()
{
	add_action("do_answer","answer");
}

string ask_quest()
{
	object ob,me;mapping ask_msg;
	ob=this_object();
	me=this_player();
	if(!me->query_temp("buzhi_jiangjing/1"))
		return "施主在说什么？贫僧可是一点都不懂啊！\n";
	if(ob->query("ask_ob")&&ob->query("ask_ob")!=me) return "施主稍后，贫僧正忙着呢！\n";
	if(ob->query("ask_ob")==me)
	return "大师还是快回答我的问题吧！\n";
	me->set_temp("buzhi_jiangjing/flag",1);
    ask_msg=ask[random(sizeof(ask))];
	ob->set("ask",ask_msg);
	ob->set("ask_ob",me);
	call_out("cancel_ask",15,me);
 	return ""+ask_msg["ask"]+",此句做何解释?\n";

}

int do_answer(string arg)
{
	object me,ob,bonze,ans;
	int lev,exp,pot,coin;
	mapping answer;
	me=this_player();
	if(!arg) return notify_fail("你想回答什么?\n");
	if(sscanf(arg,"%s %s",bonze,ans)!=2)
		return notify_fail("请使用 answer 人名 答案\n");
	if(!objectp(ob=present(bonze,environment(me))))
		return notify_fail("这里没有这个人!\n");
	if(ob->query("ask_ob")!=me)
		return notify_fail(ob->name()+"并没有问你问题!\n");
	answer=ob->query("ask");
	if(ans!=answer["answer"])
		return notify_fail("你的答案不对!\n");
	me->delete_temp("buzhi_jiangjing");
	me->delete_temp("no_quit");
	ob->delete("ask");
	ob->delete("ask_ob");
	exp=me->query("max_pot")/3+random(10)+random(10)+me->query_temp("other_give");
	pot=(int)me->query("max_pot");
	pot=pot/3+me->query_temp("other_give")/5;
	lev=30+random(5);
	coin=JIANGJING+me->query_temp("other_give")/10;
	me->add("combat_exp",exp);
	me->add("potential",pot);
        add_shili(me,exp/3,JIANGJING);
	me->improve_skill("chanzong-fofa",lev);
	me->delete_temp("other_give");
	me->delete_temp("dtsl_job");
	tell_object(me,"在这次讲经过程中,你得到了"+""HIW""+chinese_number(exp)+""NOR""+"点经验值 "+""HIW""+chinese_number(pot)+""NOR""+"点潜能 \n");
	tell_object(me,"你的"+""HIW""+"[禅宗佛法]"+""NOR""+"的修为也有了进一步的提高!\n");
	message_vision("$N合十道:大师高明,谢谢!\n",ob);
	return 1;
}
void cancel_ask(object me)
{
  if(me->query_temp("buzhi_jiangjing")){
  message_vision(YEL"和尚朝$N叹道：看来你的佛法修为还不是很高，你想想再回答吧！\n"NOR,me);
  this_object()->delete("ask");
  this_object()->delete("ask_ob");
  return;}
  return;
}
	