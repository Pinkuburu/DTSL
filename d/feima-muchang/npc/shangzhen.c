
inherit NPC;
#include <job_money.h>
#include <ansi.h>
string give_job();
void create()
{
   set_name("商震",({ "shang zhen","shang","zhen" }) );
        set("gender", "男性" );
        set("age", 50);
   set("long", "他就是飞马牧场的大管家,从侧脸看去，应是五十上下，鼻子平直，上唇的弧形
曲线和略微上翘的下唇颇具魅力，显示出他有很强的个性和自信。\n");
       
   set("combat_exp",400000);
   set("str", 26);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("tao",150);
   set_skill("strike",150);
   set_skill("cuff",150);
   set_skill("babu-ganchan",170);
   set("hand",({"liu","liang","tao"}));
   set("dodge",({"babu-ganchan"}));
   set("inquiry",([
	   "叛徒":(:give_job:),
	   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	call_out("welcome",1,ob,ob2);
	
}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	switch(random(2))
	{
	case 0: message_vision("$N冷冷地哼了一声.\n",ob2);break;
	case 1: message_vision("$N用冷眼打量着$n\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
string give_job()
{
   object me;object ob;
   ob=this_object();
   me=this_player();
   if(me->query_temp("shang_kill_pantu"))
	   return "你还是先把叛徒杀死再说吧!\n";
 /*  if(ob->query("job_time"))
	   if(time()-ob->query("job_time")<=30)
		   return "恩..这个,已经有人帮忙了,你先等会吧!\n";*/
   if(time()-me->query("busy_time")<30)
   return "你还是先歇歇吧！\n";
   if(me->query_temp("dtsl_job"))
   return "你正在做其他任务，先忙其他的吧！\n";
   if(!valid_do_job(me,"feimajob"))
	return "你的武功很高了，做这样的小事真是大才小用了！\n";
   me->set_temp("dtsl_job","飞马牧场杀叛徒任务");
   ob->set("job_time",time());
 //  call_out("cancel_shang_kill_pantu",420,me);
   switch(random(6))
   {
   case 0: me->set_temp("shang_kill_pantu/1",1);return "好吧,你去把飞马牧场的叛徒杀死,别忘了拿回他的首级!\n听说他在扬州的一座废弃的园子里藏身!\n";break;
   case 1: me->set_temp("shang_kill_pantu/2",1);return "好吧,你去把飞马牧场的叛徒杀死,别忘了拿回他的首级!\n听说他在成都的一个富户之家藏身!\n";break;
   case 2: me->set_temp("shang_kill_pantu/3",1);return "好吧,你去把飞马牧场的叛徒杀死,别忘了拿回他的首级!\n听说他经常躲藏在襄阳的街头小巷中!\n";break;
   case 3: me->set_temp("shang_kill_pantu/4",1);return "好吧,你去把飞马牧场的叛徒杀死,别忘了拿回他的首级!\n听说他经常躲藏在长安的城隍庙中!\n";break;
   case 4: me->set_temp("shang_kill_pantu/5",1);return "好吧,你去把飞马牧场的叛徒杀死,别忘了拿回他的首级!\n听说他经常躲藏在山海关的塞漠帮内!\n";break;
   case 5: me->set_temp("shang_kill_pantu/6",1);return "好吧,你去把飞马牧场的叛徒杀死,别忘了拿回他的首级!\n听说他经常躲藏在杭州的西湖旁!\n";break;
   }
   
}

void cancel_shang_kill_pantu(object me)
{
	if(!objectp(me)) {remove_call_out("cancel_shang_kill_pantu");return;}
	if(me->query_temp("shang_kill_pantu"))
	{
		tell_object(me,HIW"你做事太慢了,你的任务被取消了!\n"NOR);
		me->delete_temp("shang_kill_pantu");
		remove_call_out("cancel_shang_kill_pantu");
		return;
	}
	remove_call_out("cancel_shang_kill_pantu");
}

int accept_object(object me,object ob)
{
	int exp,sil,pot,i,j;
	object npc;
	j=10;
	npc=this_object();
	if(!me->query_temp("shang_kill_pantu"))
		return notify_fail("我可不随便要别人的东西！\n");
	if((string)ob->query("dead_id")!="tao shusheng")
		return notify_fail("你杀错人了吧？\n");
	if(ob->query("killed_by")!=me->query("id"))
	return notify_fail("哼，不是你杀的人，想来冒充吗？！\n");
	me->delete_temp("shang_kill_pantu");
	me->delete_temp("dtsl_job");
        exp=210+random(20);
        pot=me->query("max_pot")/3;
	me->add("combat_exp",exp);
	sil=FEIMA_JOB;
	pot=50+random(10);
	me->set("busy_time",time());
	me->add("potential",pot);
	me->add("deposit",FEIMA_JOB);
	add_shili(me,exp/3,FEIMA_JOB/2);
	tell_object(me,HIW"\n你被奖励了"+exp+"点经验值 "+pot+"点潜能"+sil/100+"两白银\n"NOR);
	tell_object(me,HIW"谢谢了,为我们飞马牧场做了这么大的好事!\n"NOR);
	tell_object(me,"你的钱庄存款增加了！\n");
	remove_call_out("cancel_shang_kill_pantu");
	return 1;
}

