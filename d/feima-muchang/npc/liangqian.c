
inherit NPC;

void create()
{
   set_name("梁谦",({ "liang qian","liang","qian" }) );
        set("gender", "男性" );
		
        set("age", 30);
   set("long", "他是飞马牧场专管人事的副手,所有下人都要由他来管理。\n");
       
   set("combat_exp",300000);
   set("str", 26);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",120);
   set_skill("dodge",120);
   set_skill("parry",120);
   set("dodge",({"babu-ganchan"}));

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
	case 0: message_vision("$N说道:如果闲着,可以到我这里来找活干.\n",ob2);break;
	case 1: message_vision("$N用冷眼打量着$n\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
