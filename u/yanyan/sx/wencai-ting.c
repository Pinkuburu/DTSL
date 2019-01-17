
inherit NPC;
#include <job_money.h>
#include <ansi.h>
#include "npc_list.h"
string give_job();
void create()
{
   set_name("闻采婷",({ "wen caiting","wen" }) );
        set("gender", "女性" );
		
        set("age", 32);
   set("long", "她是阴癸派的闻采婷，她的魔功在江湖上也是非常闻名。\n");
       
   set("combat_exp",500000);
   set("str", 25);
   set("per", 25);
   set("attitude", "peaceful");
   set_skill("unarmed",170);
   set_skill("dodge",170);
   set_skill("parry",170);
   set_skill("force",170);
   set_skill("sword",170);
   set_skill("strike",170);
   set_skill("cuff",170);
   set_skill("literate",170);
   set_skill("jiutian-huanzhang",170);
   set_skill("tianmo-dafa",170);
   set_skill("tianmo-jianfa",170);
   set_skill("tianmo-huanzong",170);
   set_skill("tianmo-dai",170);  
   set("gin",3000);
   set("max_gin",3000);
   set("kee",3000);
   set("max_kee",3000);
   set("sen",3000);
   set("max_sen",3000);
   set("force",3000);
   set("max_force",3000);
   create_family("阴癸派",2,"长老");
   set("class","yin3");
   set("inquiry",([
	
	   "送信":(:give_job:),
	 
	   ]));  
   setup();
  
}

string give_job()
{
	object me,letter;string str;
	string *npc_home;
	int i;
	
	me=this_player();
	if(me->query_temp("zhu_sx")) return "你还是先送完手中的信吧!\n";
	if((string)me->query("family/family_name")=="慈航静斋")
        {
	      return "慈航静斋的人我们是不会搭理的！\n";
	}
	if(time()-me->query("busy_time")<=120)
		return "你还是先歇歇吧！\n";
	if(me->query_temp("dtsl_job"))
	return "你正在做其他任务，还是先忙其他的吧！\n";	
        npc_home=keys(npc_list);
        i=random(sizeof(npc_home));
	letter=new(__DIR__"letter");
	letter->set("npc_home",npc_home[i]);
	letter->set("long","这是一封送给"+HIC+npc_list[npc_home[i]]+NOR+"的信。\n");
	letter->set("owner",me);
	letter->move(me);
	me->set_temp("zhu_sx",1);
	me->set_temp("dtsl_job","阴癸送信任务");
	if((int)me->query("combat_exp",1)>=200000)
	   {	call_out("killer_come1",10,me);
            str="路上可要小心！\n";
	}
	else str="";
	tell_object(me,query("name")+"给了一封"+letter->query("name")+"。\n");
	return "好吧，麻烦你帮我把这封"+letter->query("name")+CYN+"送给"+npc_list[npc_home[i]]+"，千万不要走漏了消息！\n"+
	       str;
	
	 
}

void killer_come1(object me)
{
	object killer,letter;
	object weapon;
	int exp;
	if(!objectp(me)||!me->query_temp("zhu_sx")) {return;}
	if(!objectp(weapon=me->query_temp("weapon")))
	killer=new(__DIR__"killer");
	else {killer=new(__DIR__"killer"+weapon->query("skill_type"));
	      }
	if(objectp(letter=present("letter",me))){	
	letter->move(killer);
	tell_object(me,HIW"剑客抢走了你的信!\n"NOR);}
	copy_object(killer,me);
	killer->create_name(killer);
	killer->delete("nickname");
	killer->delete("family");
	killer->delete("title");
	killer->set_temp("apply/armor",50+random(50));
	killer->move(environment(me));
	message_vision("$N大声道:邪教之人拿命来!\n",killer);
	killer->kill_ob(me);
    killer->set("target_id",me->query("id"));
	killer->set_leader(me);
	call_out("killer_go",180,killer);
	
	if(me->query("combat_exp")>500000)
	call_out("killer_come2",80,me);
	return;
}

void killer_come2(object me)
{
	object killer,letter;
	object weapon;
	int exp;
	if(!objectp(me)||!me->query_temp("zhu_sx")) {return;}
	if(me->is_ghost()) return;
	if(!objectp(weapon=me->query_temp("weapon")))
	killer=new(__DIR__"killer");
	else {killer=new(__DIR__"killer"+weapon->query("skill_type"));
	      }
	if(objectp(letter=present("letter",me))){
	letter->move(killer);
	tell_object(me,HIW"剑客抢走了你的信!\n"NOR);}
	copy_object(killer,me);
	killer->create_name(killer);
	killer->delete("nickname");
	killer->delete("family");
	killer->delete("title");
	killer->set_temp("apply/armor",50+random(50));
	killer->move(environment(me));
	message_vision("$N大声道:邪教之人拿命来!\n",killer);
	killer->kill_ob(me);
    killer->set("target_id",me->query("id"));
	killer->set_leader(me);
	call_out("killer_go",120,killer);
	
	return;
}

void killer_go(object killer)
{
	if(!objectp(killer))
	{ return;}
	message_vision("$N匆匆离去了！\n",killer);
	destruct(killer);
     return;
}
