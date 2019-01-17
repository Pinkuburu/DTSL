
inherit NPC;

void create()
{
   set_name("侍卫",({ "shi wei","shi","wei" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是王世充府的侍卫,保护王世充的安全。\n");
       
   set("combat_exp",500000);
   set("str", 26);
   set("per", 22);

   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/gangjian")->wield();
  
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	if(!ob||!present(ob,environment())) return; 
	if((int)ob->query("beipan",1)>=3)
		call_out("kill_pantu",1,ob,ob2);
	return;
}

void kill_pantu(object ob,object ob2)
{
	if(!ob) return;
	message_vision("$N朝$n冷笑道:象你这种多个势力的叛徒，休想逃走!\n",ob2,ob);
    ob2->kill_ob(ob);
	remove_call_out("kill_pantu");
	return;
}
