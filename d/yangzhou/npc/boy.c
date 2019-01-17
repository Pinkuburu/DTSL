
inherit NPC;

void create()
{
   set_name("小男孩",({ "boy"}) );
   set("gender", "男性" );
   set("age", 12);
		
   set("long", "这是在扬州城居住的小男孩。\n");
       
   set("combat_exp", 5000);
   set("str", 20);
   set("per", 25);
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
   
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

