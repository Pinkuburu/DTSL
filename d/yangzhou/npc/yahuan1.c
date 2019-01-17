
inherit NPC;

void create()
{
   set_name("丫鬟",({ "ya huan","ya","huan"}) );
   set("gender", "女性" );
   set("age", 22);
		
   set("long", "这是画舫上的丫鬟。\n");
       
   set("combat_exp", 30000);
   set("str", 20);
   set("per", 20);
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
 
   set("chat_chance",30);
   set("chat_msg",({
	   "丫鬟微微一笑：我家小姐等的可着急呢！\n",
	   (:do_command,"bf":),
	   (:do_command,"shy":),
	  
  }));
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
 
}

