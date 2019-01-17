
inherit NPC;
#include <ansi.h>
#include <job_money.h>

#define CTRL_D __DIR__"jctrl.c"

string give_job();
int cancel_job();
int do_ok(string arg);
int do_action1();

string *dir=({
"/d/suiye","/d/dingxiang","/d/mayi",
"/d/tuyuhun"});

void create()
{
   set_name("马贼",({ "ma zei","ma","zei" }) );
   set("gender", "男性" );
   set("age",35);
   set("long", "这是一名马贼，到处抢劫来往的客商。\n");
       
   set("combat_exp",80000);
  
   set("force",200);
   set("max_force",200);
   set_skill("force",30);
  
   set("inquiry",([
	   "打劫":(:give_job:),
	   "放弃":(:cancel_job:),
	   "加入":(:do_action1:),
	   ]));
   
   set("chat_chance",30);
   set("chat_msg",({
    (:do_command,"thief":),
    (:do_command,"envy":),
   }));
   
   setup();
  
}

void init()
{
	add_action("do_ok","jiaochai");
}

string give_job()
{
	object me;
	object target;
	int flag;
	
	
	me=this_player();
	
	if(!CTRL_D->if_join(me))
	return "你不是马贼，如何帮我打劫？？\n";
		
	if(me->query_temp("mazei_job"))
	return "你快去打劫吧，不然一会人都走了！\n";
	
	if(me->query("combat_exp")<100000)
	 return "你的本领太低了，歇着去吧！\n";
	
  	if(time()-me->query("busy_time")<=30+random(5))
		return "你先歇歇吧！\n";
	if(me->query_temp("dtsl_job"))
        return "你正在做其他任务，先忙其他的吧！\n";
        if(!valid_do_job(me,"dajie"))
	return "你的武功很高了，做这样的小事真是大才小用了！\n";
                
	target=new(__DIR__"target");
	target->set("last",time());
	
	flag=target->set_status(me);
	
	if(!random_place(target,dir))
	 return "现在哪里可以打劫呢？让我想想... ...\n";	
	
	if(!(environment(target)))
          return "现在哪里可以打劫呢？让我想想... ...\n";
               
	me->set_temp("dtsl_job","马贼打劫任务");
	me->set_temp("mazei_job",1);
	me->add_temp_array("job_temp_killer",target);
	
	if(flag==1)	
	return "好吧，既然"+RANK_D->query_respect(me)+"愿意，你就去"+MISC_D->find_place(environment(target))+"\n"+
	"打劫"+target->name()+"，记着，一定要把对方杀死！\n";
	else
	return "好吧，既然"+RANK_D->query_respect(me)+"愿意，你就去"+MISC_D->find_place(environment(target))+"\n"+
	"打劫"+target->name()+"，记着，我不想把事情闹大，不要杀死对方！\n";
	
}

int cancel_job()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("mazei_job")){
	command("heng "+ob->query("id"));
	command("say 你在说什么？");
	return 1;}
   
   JOBSYS_D->do_cancel_job("mazeijob",ob,this_object());
   	
     command("sigh "+ob->query("id"));
     command("say 既然你这么没用，我也没有办法了！\n");
     return 1;
}

int accept_fight(object who)
{
   return 0;
}


int do_action1()
{
   object ob;
   
   ob=this_player();
   
   if(CTRL_D->is_full()){
     command("say 谢了，我的兄弟已经够多了！");
     return 1;
   }
   if(CTRL_D->if_join(ob)){
     command("say 你既然已经入伙，就赶快打劫吧！");
     return 1;
   }
   
   CTRL_D->add_member(ob);
      
   command("say 好，看你胆量不小，我就让你入伙！");   
   return 1;
}

void die()
{
   object ob,book;
   
   ob=query_temp("last_damage_from");
   
   if(!ob) return ::die();
   
   if(ob->query("family/family_name")=="突厥"
    &&ob->query("combat_exp")>=1000000
    &&!ob->query("dtsl_quest_help_toutianjf")){
      book=new(__DIR__"obj/book");
      book->move(this_object());
      ob->set("dtsl_quest_help_toutianjf",1);
      ob->set_temp("cannot_get_jianpu",1);
   }
   
   return ::die();
   
}