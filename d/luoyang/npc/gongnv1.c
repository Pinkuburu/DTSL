
inherit NPC;

void create()
{
   set_name("宫女",({ "gong nv","gong","nv" }) );
        set("gender", "女性" );
        set("age", 20);
   set("long", "这是洛阳皇宫的一个宫女。\n");
       
   set("combat_exp", 50);
   set("str", 10);
   set("per", 22);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	object ob;
	ob=this_player();
	
	if(!ob||is_fighting()) return;
	remove_call_out("welcome");
	call_out("welcome",1,ob);
	
}

void welcome(object ob)
{
   if(!ob) return;
   if(environment(ob)!=environment(this_object()))
   return;
	switch(random(2))
	{
	case 0:
	command("say 整天呆在皇宫里，可真是闷死我了！");
	break;
	
	case 1:
       command("say 什么时候能出宫，嫁个如意郎君呢？");
	}
	
}
