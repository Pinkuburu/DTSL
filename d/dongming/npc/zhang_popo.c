
inherit NPC;

#include <ansi.h>
#include <job_money.h>

string give_job();
int cancel_job();

void create()
{
       set_name("张婆婆", ({ "zhang popo", "zhang","popo" }) );
       set("gender", "女性" );
     
       set("age", 50);
       set("long",
               "她是东溟派的弟子。\n");
       set("combat_exp",450000);
       set("attitude", "peaceful");
       set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("max_qi", 1500);
        set("max_jing", 1500);
        set("eff_jingli", 1500);
        set("jing", 1500);
        set("jingli", 1500);
        set("eff_jing", 1500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali",100);
        set("target_id","###");
        create_family("东溟派",4,"弟子");
    	set("inquiry",([
			"job":(:give_job:),
			"放弃":(:cancel_job:),
			]));
       

 
       setup();
 carry_object(__DIR__"obj/cloth")->wear();
 carry_object(__DIR__"obj/changjian")->wield();
 
 
}
void init()
{
        object ob;

        ::init();add_action("do_ok","task");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
	 

	if (!ob || !present(ob, environment())) return;
	switch( random(2) ) {
		case 0:
			say( "张婆婆说道：你是"+ob->query("name")
          + "么？,快来这里干活吧!\n");
			break;
		case 1:
			say( "张婆婆说道:你好好努力!!\n");
			break;
	}

}

string give_job()
{
	object ob,thing;ob=this_player();
	if((int)ob->query("combat_exp",1)>150000)
		return "以你现在的身手做这样简单的任务太可惜了!\n";
	if(ob->query_temp("popo_job"))
		return "东溟派的弟子做事可没有虎头蛇尾的!\n";
	if(ob->query("family/family_name")!="东溟派")
		return "只有东溟派的弟子可以在这里干活！\n";
	if(time()-ob->query("busy_time")<=30)
		return "你还先歇歇吧！\n";
	if(ob->query_temp("dtsl_job"))
   return "你正在做其他任务，先忙其他的吧！\n";
   ob->set_temp("dtsl_job","东溟派初级任务");
	switch(random(3))
	{
	case 0:ob->set_temp("popo_job",1);ob->set_temp("popo_job1",1);ob->set_temp("count",1);return "好吧,你去竹林种竹子(zhong 竹子)吧!\n";break;
    case 1:ob->set_temp("popo_job",1);ob->set_temp("popo_job2",1);ob->set_temp("count",1);return "好吧,你去打扫青云宫(sao 宫)吧!\n";break;
    case 2:ob->set_temp("popo_job",1);ob->set_temp("popo_job3",1);ob->set_temp("count",1);return "好吧,你去兵器库磨兵器(mo 兵器)吧!\n";break;
    
    }
}

int do_ok(string arg)
{
	
	object ob=this_player();
	
	if(!arg||arg!="ok") return notify_fail("你想说什么?\n");
    if(!ob->query_temp("popo_ok"))
		return notify_fail("东溟派弟子做事可没有虎头蛇尾的!\n");
    ob->delete_temp("popo_ok");
    ob->delete_temp("dtsl_job");
    
    JOBSYS_D->give_reward_dmchujijob(ob);
    
    return 1;
}

int cancel_job()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("popo_job")){
   command("?");
   return 1;
   }
   JOBSYS_D->do_cancel_job("dmchujijob",ob,this_object());
   command("sigh");
   return 1;
}

   