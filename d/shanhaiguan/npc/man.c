
inherit NPC;

void create()
{
   set_name("青年",({ "man" }) );
        set("gender", "男性" );
        set("age", 25);
   set("long", "这是一个青年男子，看起来好象很有文化。\n");
       
   set("combat_exp", 500+random(500));
   setup();
   //carry_object("/d/gaoli/obj/cloth")->wear();
  
}

