
inherit NPC;
inherit JOIN;
void create()
{
   set_name("官员",({ "guan yuan" }) );
        set("gender", "男性" );
        set("age", 42);
   set("long", "他是彭梁的官员，专门负责士兵的训练。\n");
       
   set("combat_exp", 500000);
//  set("shili","wang");
   set("str", 10);
   set("per", 22);
   set("attitude", "peaceful");
   
   setup();
   carry_object(__DIR__"obj/guanfu")->wear();
  
}



