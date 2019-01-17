
inherit NPC;

void create()
{
   set_name("兰姑",({ "lan gu","lan","gu" }) );
        set("gender", "女性" );
		
        set("age", 22);
   set("long", "她负责打理厨房的总务。\n");
       
   set("combat_exp",1000);
   set("str", 20);
   set("per", 21);
   set("attitude", "peaceful");
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
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
	case 0: message_vision("$N大声说道:不干活,在这里白吃啊?!.\n",ob2);break;
	case 1: message_vision("$N用冷眼打量着$n\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
