
inherit NPC;

void create()
{
   set_name("老者",({ "old"}) );
        set("gender", "男性" );
        set("age", 62);
		
   set("long", "这是在襄阳城居住的的老者。\n");
       
   set("combat_exp", 5000);
   set("str", 20);
   set("per", 25);
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
  set("attitude", "peaceful");

   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

