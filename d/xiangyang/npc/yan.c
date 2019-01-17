
inherit NPC;

void create()
{
   set_name("言老大",({ "yan laoda","yan","lao","da" }) );
        set("gender", "男性" );
        set("age", 32);
		set("title","竹花帮头目");
   set("long", "这是竹花帮的头目言老大,在扬州城还算是很有势力。\n");
       
   set("combat_exp", 80000);
   set("str", 26);
   set("per", 22);
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
   set_skill("stick",50);
   set("attitude", "peaceful");
   set("chat_chance",70);
   set("chat_msg",({
	   "言老大拍拍胸脯:到扬州城找我准没错!\n",
	   "言老大笑道:竹花帮在扬州还是很有势力的!\n",
		   (:random_move:),
   }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/zhugun")->wield();
  
}

