
inherit NPC;

void create()
{
   set_name("官兵",({ "bing" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是一个在驿站休息的官兵。\n");
       
   set("combat_exp",200000);
   set("str", 26);
   set("per", 22);
   set("guard","hefei");
   set("shili","luoyang");
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/junfu")->wear();
   carry_object(__DIR__"obj/gangjian")->wield();
  
}

void init()
{
	object *ob,here,me;int i;
	me=this_object();
	here=environment(me);
	ob=all_inventory(here);
	for(i=0;i<sizeof(ob);i++)
	{
	
     if(ob[i]->query("killer")==me->query("guard"))
		call_out("kill_killer",1,ob[i],me);
	 else if((int)ob[i]->query("beipan",1)>=3)
		call_out("kill_pantu",1,ob[i],me);
	}
	return;
}

void kill_pantu(object ob,object ob2)
{
	if(!ob||!ob2) {remove_call_out("kill_pantu");return;}
	message_vision("$N朝$n冷笑道:象你这种多个势力的叛徒，休想逃走!\n",ob2,ob);
    ob2->kill_ob(ob);
	remove_call_out("kill_pantu");
	return;
}
void kill_killer(object ob,object ob2)
{
	if(!ob||!ob2) {remove_call_out("kill_killer");return;}
	ob2->kill_ob(ob);
	remove_call_out("kill_killer");return;
}