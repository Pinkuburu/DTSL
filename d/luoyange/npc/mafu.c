
inherit NPC;

void create()
{
   set_name("马夫",({ "ma fu","ma","fu" }) );
        set("gender", "男性" );
        set("age", 30);
   set("long", "这是飞马牧场的马夫。\n");
       
   set("combat_exp", 80000);
   set("str", 25);
   set("per", 22);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if((!ob||!present(ob,environment())||ob2->is_fighting())&&ob->query("race")=="人类") return;
	call_out("welcome",1,ob,ob2);
	
}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	switch(random(2))
	{
	case 0: message_vision("$N对$n笑道:这位"+RANK_D->query_respect(ob)+",你是来买马的吗?\n",ob2,ob);break;
	case 1: message_vision("$N对$n说道:这位"+RANK_D->query_respect(ob)+",如果生活困难,可以在我们这里干活啊!\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
