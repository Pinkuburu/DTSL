
inherit NPC;

void create()
{
   set_name("女弟子",({ "girl" }) );
        set("gender", "女性" );
        set("age", 20);
   set("long", "这是宋家堡的弟子，武功也是不俗。\n");
       
   set("combat_exp", 50000);
   set_skill("blade",30);
   set_skill("tiandao-bajue",30);
   set_skill("dodge",30);
   set_skill("force",30);
   set("force",200);
   create_family("宋家堡",7,"弟子");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
  
}

