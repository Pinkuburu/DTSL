
inherit NPC;

void create()
{
   set_name("歌妓",({ "ge ji","ge","ji"}) );
   set("gender", "女性" );
   set("age", 22);
		
   set("long", "这是画舫上的跳舞助兴的歌妓。\n");
       
   set("combat_exp", 30000);
   set("str", 20);
   set("per", 30);
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
 
}

