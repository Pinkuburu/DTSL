
inherit NPC;

void create()
{
   set_name("大汉",({ "da han","da","han" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是海沙帮的帮众。\n");
       
   set("combat_exp", 6000);
   set("str", 24);
    set("attitude", "friendly");
    set("shili",([
      "name":"haisha_b",
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
	case 0: message_vision("$N大声道：江南一带，也就是我们海杀帮最有势力!\n",ob2);break;
	case 1: message_vision("$N打量了$n几眼\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
