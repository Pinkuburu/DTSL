
inherit NPC;

void create()
{
   set_name("小男孩",({ "boy"}) );
        set("gender", "男性" );
        set("age", 12);
		
   set("long", "这是在书院读书的小男孩。\n");
       
   set("combat_exp", 5000);
   set("str", 20);
   set("per", 25);
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
  set("attitude", "peaceful");
   set("chat_chance",30);
   set("chat_msg",({
	   "小男孩读道:[人之初,性本善.  性相近,习相远]\n",
	   "小男孩读道:[知之为知之,不知为不知]!\n",
   }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

