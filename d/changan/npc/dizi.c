
inherit NPC;

void create()
{
   set_name("弟子",({ "di zi","di","zi" }) );
        set("gender", "男性" );
        set("age", 22);
   set("long", "这是在武馆学习武艺的弟子。\n");
       
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("dodge",50);
   set_skill("parry",50);
   set_skill("unarmed",50);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

