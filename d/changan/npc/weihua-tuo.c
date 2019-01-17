
inherit NPC;
#include <ansi.h>
#include <job_money.h>
string give_job();
int do_ok(string arg);
void create()
{
   set_name("韦华佗",({ "wei huatuo","wei"}) );
        set("gender", "男性" );
        set("age", 35);
   set("long", "这就是李阀的御医，医术高明，人称[华佗再世]。\n");
   set("combat_exp", 200000);
   set("str", 28);
   set("per", 26);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("parry",150);
   set_skill("dodge",150);
   set_skill("force",150);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   set_skill("literate",100);
   set("inquiry",([
	   "采药":(:give_job:),
	   ]));
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

string give_job()
{
	object me,ob,tool;
	me=this_player();ob=this_object();
	
	if(me->query("vocation")!="药师")
	return "只有药师才能帮我采药。\n";
	if(me->query_temp("wei_job"))
		return "做事可不要马马乎乎啊！\n";
	if(me->query_temp("wei_ok"))
		return "你还是把草药给我吧！\n";
	if(time()-me->query("busy_time")<60)
		return "你还是歇歇吧！\n";
	if(me->query_temp("dtsl_job"))
   return "你正在做其他任务，先忙其他的吧！\n";
   me->set_temp("dtsl_job","长安韦华佗采药任务");
	switch(random(3))
	{
	case 0:me->set_temp("wei_job/1",1);break;
	case 1:me->set_temp("wei_job/2",1);break;
	case 2:me->set_temp("wei_job/3",1);break;
	}
	tool=new(__DIR__"obj/chutou");
	tool->move(me);
	return "好吧，麻烦"+RANK_D->query_respect(me)+"到华山帮我采点药吧！\n";
}

int accept_object(object me,object ob)
{
	int v_score;
	if(!me->query_temp("wei_ok"))
		return notify_fail("这是你挖的草药吗？不要偷懒啊！\n");
	if(!ob->query("wei_med"))
		return notify_fail("这是从华山挖的草药吗？不要偷懒啊！\n");
	
	v_score=me->query_int()*me->query("max_pot");
	me->delete_temp("wei_ok");
	me->delete_temp("dtsl_job");
	me->set("busy_time",time());
	me->improve_skill("bencao-shuli",v_score);
	tell_object(me,"你的本草术理有了进一步的提高！\n");
	if(present("chu tou",me))
	  destruct(present("chu tou",me));
	return 1;
}