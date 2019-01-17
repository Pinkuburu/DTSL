
inherit NPC;

#include <ansi.h>
#include <job_money.h>

#define TIME_TICK1 time()*60
string *list=({

"killer",

	});
int work_me();
int cancel_me();
int delete_ask(object me);
int do_kill(string arg);

string do_quest1();
void create()
{
   int i;
   object *ob;
   
   set_name("杨虚彦",({ "yang xuyan","yang" }) );
   set("gender", "男性" );
   set("nickname","影子刺客");
   set("age", 32);
   set("long", "这就是武林中闻名的影子刺客。\n");
       
   set("combat_exp", 1000000);
   set("str",30);
   set("per", 22);
   set("dex",30);
   
   set("max_gin",3000);
   set("max_kee",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
   
   set_skill("force",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("sword",200);
   
   set_skill("yingzi-jianfa",200);
   set_skill("huanmo-shenfa",200);
   set_skill("wanshi-jue",200);
 
   set("inquiry",([
//	  "杀人": "好吧，请用 cisha 人物id  来告诉我杀谁吧!\n",
//        "暗杀": "好吧，请用 cisha 人物id  来告诉我杀谁吧!\n",
//	  "刺杀": "好吧，请用 cisha 人物id  来告诉我杀谁吧!\n",
          "kill": (: work_me :),
	  "杀人": (: work_me :),
	  "放弃": (: cancel_me :),
	  "五毒书":(:do_quest1:),
	   ]));
   set("vocation","杀手");
   set_temp("apply/armor",100);
   setup();
   ob=children(__DIR__"obj/qingfeng-jian");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"你手中的"+ob[i]->query("name")+"被它的主人收回去了！\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"被一阵风卷走了。\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
   carry_object(__DIR__"obj/qingfeng-jian")->wield();
  
}

void init()
{
	//add_action("do_kill","cisha");
	add_action("do_teach","qingjiao");
}

int do_kill(string arg)
{
	object *usr;object me,ob;int i,j;object victim;
	int vexp,gol;int money;
	me=this_player();
	ob=this_object();
	usr=users();
	if(!arg) return notify_fail("你让我去杀谁？明说好了!\n");
	j=0;
	if(me->query("id")==arg) return notify_fail("杀你自己？开玩笑吧？！\n");
	for(i=0;i<sizeof(usr);i++)
	{
		if(usr[i]->query("id")==arg)
		{ j=1;victim=usr[i];break;}
	}
	if(j==0) return notify_fail("恩？现在的江湖中有这个人吗？好好看看!\n");
	if(victim->is_ghost())
	return notify_fail("这个人已经死了，你还是积点阴德吧！\n");
	vexp=victim->query("combat_exp");
	gol=vexp/1000+random(vexp/1000);
	if(gol<=0) return notify_fail("哼，武功这么低微的人也值得我来杀?\n");
	tell_object(me,"这次行动要花掉你"+chinese_number(gol)+"两黄金!\n");
	money=gol*10000;
	switch(MONEY_D->player_pay(this_player(), money))
	{
	case 0: return notify_fail("哼，这么点钱，也想来找我？\n");
	case 2: return notify_fail("您的零钱不够了，银票又没人找得开。\n");
	default:
	tell_object(me,"杨虚延点点头，道：收人钱财，与人消灾，你等着好了！\n");
	if(victim->query("combat_exp")>500000)
	ob->set("combat_exp",victim->query("combat_exp"));
	if(!objectp(victim)) return notify_fail("哎呀，这个人突然跑了，下次吧!\n");
	victim->start_busy(2);
	message_vision("$N身行一晃，踪迹不见!\n",ob);
	ob->move(environment(victim));
	message_vision(HIR"$N冲着$n叫道：有人雇我来杀你，你认命好了!\n"NOR,ob,victim);
	ob->kill_ob(victim);
log_file("killer_kill",sprintf("%s let yang kill %s\n",me->query("id"),victim->query("id")));
	call_out("yang_go",180,ob);
	return 1;
	}
	return 1;
}

void yang_go(object ob)
{
	string *dir=({"/d/luoyang/shanlu1","/d/xiangyang/tulu2","/d/chengdu/shulin1"});
	if(!objectp(ob))
	{ remove_call_out("yang_go");return;}
	message_vision("$N四下看了看，身行一晃，踪迹不见!\n",ob);
	ob->move(dir[random(sizeof(dir))]);
	remove_call_out("yang_go");return;
}

int prevent_learn(object me,string skill)
{
   
   if(me->query("vocation")==query("vocation")){
   	if(skill!=query("vocation_skill")&&skill!="wanshi-jue"){
          command("say 我只传授"+to_chinese(query("vocation_skill"))+
             "「"+query("vocation_skill")+"」和"+
             to_chinese("wanshi-jue")+"「wanshi-jue」！");
          
          return 1;
        }
       return 0;
   } 
   else if(skill!="wanshi-jue")
        return 1;
   
   return 0;
}

int is_apprentice_of(object ob)
{
	return 1;
}
int recognize_apprentice(object ob)
{
         return 1;
}

int cancel_me()
{	
	
	object me=this_player();

           if(!me->query_temp("cisha/name"))
	   
	{
	   command("bite");
	   command("say 有人让你杀吗？，来凑什么热闹！\n");
	   return 1;
       }
        
        // 放弃任务：
        JOBSYS_D->do_cancel_job("killerjob",me,this_object());
	
	command("shrug");
	command("say 你既然不能帮我杀人，也只好算了。\n");	
	return 1;
}
 
int work_me()
{
	object me;
	me=this_player();
	
	if(me->query("vocation")!="杀手"){
	 command("say 只有杀手可以做这个任务。\n");
	 return 1;}
	
	if(me->query("combat_exp")<100000){
	command("say 你的本领太低了，无法做这个任务的。\n");
	return 1;
	}
	
	   if(me->query_temp("cisha/name"))
	   {
		command("heng");
		command(
 		  "say 我不是已经派你去刺杀"+me->query_temp("cisha/name")
		  +"吗？还楞着？快去啊！\n");
		return 1;
	    }
	   
	   if(time()-me->query("busy_time")<30){
	   	
		command("heng");
		command(
 		  "say 这样的生意不是总有的，等会吧！\n");
		return 1;
	    }
	   
	   if(me->query_temp("dtsl_job")){
	   command("heng");
		command(
 		  "say 你正在做别的任务，先忙着去吧！\n");
		return 1;
	    }
	    
	    if(me->is_busy()){
	     command("say 你正忙着呢！\n");
	     return 1;}
	   
	    
	me->set_temp("cisha");
	me->set_temp("dtsl_job","杀手任务");
	me->set("busy_time",time()-20);
	me->start_busy(1);
	call_out("start_job", 1, me);
	return 1;
}
int start_job(object me)
{	
	string where;
	object killer;
	int lvl;

	if(environment(me)!=environment()) return 1;
	
	lvl=me->query_temp("cisha_job/level");
	
        killer = new("/d/job/killerjob/"+list[random(sizeof(list))]);
        where=killer->invocation(me,lvl);
	
	message_vision("$N跟身边的手下耳语了几句！\n",this_object());
        message_vision("$N对"HIR"$n"NOR"说道：某人委托刺杀的"+where+"出现了，"
		+"我无暇分身，你去帮我把他杀了吧！\n"
		,this_object(),me);

	me->set_temp("cisha/name",killer->query("name"));
	//此处增加一个 job_temp_killer 数组变量，在 quit 或 放弃、完成时
	// jobsysd.c 将清除这个物件：
	me->add_temp_array("job_temp_killer",killer);
	return 1;
}

//断肠草和羊角扭 为需要的物品。
string do_quest1()
{
  object ob;
  string str1,str2;
  
  ob=this_player();
  if(ob->query("vocation")!="药师")
  return "我只传授药师这项毒术！\n";
  if(ob->query("dtsl_quest_poison_ok"))
  return "我早已传授给你毒术的机要，你还来问什么？\n";
  ob->add_temp("ask_times",1);
  if(ob->query_temp("ask_times")>40)
  ob->set_temp("ask_times",random(10));
  str1=CHINESE_D->chinese_date(TIME_TICK1);
  str2=CHINESE_D->chinese_date((ob->query("birthday") -14*365*24*60)*60);
  if(str1[sizeof(str1)-8..sizeof(str1)]!=str2[sizeof(str2)-8..sizeof(str2)]||
   ob->query_temp("ask_times")!=ob->query("kar"))
  return "我看你悟性甚佳，但此时尚不是传授你此毒术的时机！\n";
  ob->set("dtsl_quest_poison_ok",1);
  return "炼制这样的毒药需要两个物品，你能不能帮我找一下？\n";
}

int accept_object(object who,object ob)
{
    object book;
    
    if(!who->query("dtsl_quest_poison_ok"))
    return 0;
    if(ob->query("quest_poison")&&
    !who->query_temp(ob->query("poison_id"))&&
     who->query_temp("poison_find")<2){
    who->add_temp("poison_find",1);
    if(who->query_temp("poison_find")==2){
    	book=new(__DIR__"obj/book");
    	book->move(who);
    	tell_object(who,query("name")+"给了你一本"+book->query("name")+"。\n");
    	return 1;}
    return 1;}
   return 0;
}
    
