
inherit NPC;

void create()
{
   set_name("流氓",({ "liu mang","liu","mang"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是一位在长安城鬼混的流氓。\n");
       
   set("combat_exp", 10000);
   
   
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

