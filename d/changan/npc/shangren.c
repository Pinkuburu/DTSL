
inherit NPC;

void create()
{
   set_name("商人",({ "shang ren","shang","ren" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是一位在长安城做生意的商人\n");
       
   set("combat_exp", 200000);
   set("str", 28);
   set("per", 22);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

