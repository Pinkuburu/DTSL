
inherit NPC;

void create()
{
   set_name("卖花姑娘",({ "girl"}) );
        set("gender", "女性" );
        set("age", 22);
   set("long", "这是花店的卖花姑娘，她这里的花很好，有很多人来买。\n");
   set("combat_exp", 1000);
   set("str", 20);
   set("per", 24);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/baishayi")->wear();
  
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
	case 0: message_vision("$N笑道:来看看这里的花吧!\n",ob2);break;
	case 1: message_vision("$N冲$n笑道：我这里的花品种很多的，您多看看吧！\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
