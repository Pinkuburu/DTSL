
inherit NPC;

void create()
{
   set_name("王世充",({ "wangshi chong","wang","shi","chong" }) );
        set("gender", "男性" );
        set("age", 42);
   set("long", "他就是洛阳的城主王世充，他的手下好手众多。\n");
       
   set("combat_exp", 3000000);
   set("str", 20);
   set("per", 20);
   set("shili","wang");
   set("jiangtu",({"luoyang"}));
   set("king",1);
   set("attitude", "peaceful");
    set_skill("dodge",300);
    set_skill("parry",300);
    set_skill("force",300);
    set_skill("finger",300);
    set_skill("dujie-zhi",300);
    set_skill("lianhua-step",300);
    set_skill("literate",300);
    set_skill("chanzong-fofa",310);
    set_skill("wuxiang-shengong",300);
    set_skill("bikouchan",300);

    set("perform_quest/liudao",1);
    set("apply_points",2000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: command("perform liudao") :),
        (: command("execute wuyu") :),
    }));
   setup();
   carry_object(__DIR__"obj/guanfu")->wear();
  
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
	case 0: message_vision("$N笑道:这位"+RANK_D->query_respect(ob)+",不如来投奔我好了!\n",ob2);break;
        case 1: message_vision("$N微笑地看着$n。\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}
