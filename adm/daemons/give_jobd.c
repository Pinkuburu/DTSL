//create by zanlin
//1999.8.22
#include <ansi.h>
int time_period(int timep, object me);
mapping query_quest();
string sysmsg;
int accept_object(object who, object ob)
{
        int  exp, pot, score, val;
	string test;
	mapping quest;
	if(!(quest =  who->query("quest")))
	{
       tell_object(who,this_object()->name()+"说道：我什么时候请你帮忙了？\n");
	return 0; 
	}
        if( (string)ob->query("name") != quest["quest"] || 
            (string)who->query("questnpc")!=this_object()->name())
        {
            tell_object(who,this_object()->name()+"说道：这东西对我来说没什么用处。\n");
            return 0;
        }
	if ((int) who->query("task_time") < time() )
        {
        return notify_fail(this_object()->name()+"说道：真可惜！现在我已经不是很急着需要它了！\n");
        return 1;
        }
        else
        {
        tell_object(who,
              this_object()->name()+ "说道：啊！你这么快就把它找到了！非常感谢，我正急着用呢。\n");
	exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2)+1;
// put a cap
	if(exp > 150) exp = 150;
       if(who->query("quest_num"))
          exp = exp * (int) who->query("quest_num");
	pot = exp / 5 + 1;
//	score = quest["score"]/2 + random(quest["score"]/2);
//	score = -1;
	who->add("combat_exp",exp);
	who->add("potential",pot);
	who->add("score",score);
       tell_object(who,HIW"不经意间，你发现自己增加了：\n" +
	chinese_number(exp) + "点实战经验\n"+
	chinese_number(pot) + "点潜能\n" NOR);
	who->set("quest", 0 );
       call_out("destroy",1,ob);
       return 1;
        }
                return 1;
}

int give_job(string arg)
{
	mapping quest ;
	object me;
	int j, combatexp, timep, lvl=0;
        mixed *local;
        int  t;
        string questmsg;
	me = this_player();
	//if((int) me->is_ghost())
//{
//		write("说道：．\n");
//		return 1;
//	}


        if((quest =  me->query("quest")))
	{
	if( ((int) me->query("task_time")) >  time() )
		return notify_fail(this_object()->name()+"笑了笑，说道：你还有别的事要做，不敢有劳你了。\n");
       else
        if(me->query("quest_num"))me->delete("quest_num");
	}
    
 if(random(10)>1)
  {
     quest = query_quest();

      //	timep = quest["time"];	
	timep = 600;  
       tell_object(me,HIW+this_object()->name()+"说道：\n"NOR);
        if(questmsg=quest["msg"])
            tell_object(me,HIW+questmsg+NOR);
       tell_object(me,HIW+"帮个忙,"NOR);
	timep = random(timep/2)+timep/2;
	time_period(timep, me);

	if (quest["quest_type"] == "寻")
	{
        tell_object(me,"找回『"+quest["quest"]+"』给"+"我。\n" NOR);
	sysmsg +="找回『"+quest["quest"]+"』。";
	}
	        if (quest["quest_type"] == "杀")
        {
        tell_object(me,"替我杀了『"+quest["quest"]+"』。\n" NOR);
	sysmsg +="杀了『"+quest["quest"]+"』。";
        }
 	me->set("quest", quest);
	me->set("task_time", (int) time()+(int) timep);
       me->set("questnpc",this_object()->name());
	 
       if(me->query("quest_num")<3)me->add("quest_num",1);
	
	CHANNEL_D->do_channel(this_object(), "qst", sprintf("%s(%s)：%s", 
	me->query("name"),me->query("id"),sysmsg));
       return 1;
}
 else 
 return notify_fail(this_object()->name()+"摇了摇头，说道：现在我没什么着急事需要你帮忙。\n");

}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me,HIW + sprintf("%s","请在" + time + "内"));
	 sysmsg = "在" + time + "内";
        return 1;
}
void destroy(object item)
{
 destruct(item);
}

