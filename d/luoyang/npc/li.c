
inherit NPC;
void create()
{
   set_name("李官员",({ "li" }) );
        set("gender", "男性" );
        set("age", 42);
   set("long", "他是王世充的得力助手，专门帮王世充招募有才之士。\n");
       
   set("combat_exp", 500000);
   set("shili","wang");
   set("str", 10);
   set("per", 22);
   set("attitude", "peaceful");
   
   setup();
   carry_object(__DIR__"obj/guanfu")->wear();
  
}

void init()
{
}


