
inherit NPC;

void create()
{
   set_name("弟子",({ "di zi","di","zi" }) );
        set("gender", "女性" );
		
        set("age", 22);
   set("long", "这是阴癸派的弟子.\n");
       
   set("combat_exp",700000);
   set("str", 25);
   set("per", 25);
   set("attitude", "peaceful");
   set_skill("dodge",192);
   set_skill("parry",192);
   set_skill("force",192);
   set_skill("sword",192);
   set_skill("tianmo-dafa",192);
   set_skill("tianmo-jianfa",192);
   set_skill("tianmo-huanzong",192);
   set("gin",2000);
   set("max_gin",2000);
   set("kee",2500);
   set("max_kee",2500);
   set("sen",2000);
   set("max_sen",2000);
   set("force",2500);
   set("max_force",2500);
   create_family("阴癸派",7,"弟子");
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}
