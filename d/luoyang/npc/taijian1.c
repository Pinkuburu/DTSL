
inherit NPC;

void create()
{
   set_name("太监",({ "tai jian","tai","jian" }) );
        set("gender", "男性" );
        set("age", 30);
   set("long", "这是洛阳皇宫的一个太监。\n");
       
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
	command("say 皇上这几天还要美女，可真是愁坏我了！");
	break;
	
	case 1:
	command("say 下午没事，就找小张子赌钱去！");
	}
	
}
