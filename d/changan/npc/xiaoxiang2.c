
inherit NPC;

void create()
{
   set_name("小香",({ "xiao xiang","xiang" }) );
        set("gender", "女性" );
        set("age", 22);
   set("long", "这是[风雅阁]的姑娘小香。\n");
   set("jinv",1);
   set("combat_exp", 1000);
   set("str", 10);
   set("per", 26);
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
	case 0: message_vision("$N笑道:呦，这位客官，来坐坐嘛!\n",ob2);break;
	case 1: message_vision("$N冲$n笑道：我们[风雅阁]的姑娘可都是漂亮的，包您满意！\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
