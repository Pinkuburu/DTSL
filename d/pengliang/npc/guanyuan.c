
inherit NPC;
inherit JOIN;
void create()
{
   set_name("官员",({ "guan yuan" ,"guan"}) );
        set("gender", "男性" );
        set("age", 42);
   set("long", "他是彭梁的官员，专门负责商贾的税收。\n");
       
   set("combat_exp", 500000);
//  set("shili","wang");
   set("str", 10);
   set("per", 22);
   set("attitude", "peaceful");
   
   setup();
   carry_object(__DIR__"obj/guanfu")->wear();
  
}



