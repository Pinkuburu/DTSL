
inherit NPC;

void create()
{
   set_name("弟子",({ "di zi","di","zi" }) );
        set("gender", "男性" );
		
        set("age", 22);
   set("long", "这是飞马牧场的弟子。\n");
       
   set("combat_exp",9000);
   set("str", 20);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}


