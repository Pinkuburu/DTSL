

inherit NPC;
void create()
{
   set_name("康鞘利",({ "kang qiaoli","kang" }) );
        set("gender", "男性" );
		
        set("age", 26);
   set("long", "他就是突厥在中原的耳目。\n");
       
   set("combat_exp",300000);
   set("str", 25);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",120);
   set_skill("dodge",120);
   set_skill("parry",120);
   set_skill("force",120);
   set_skill("blade",120);
   set_skill("literate",120);
   set_skill("cuff",120);
   set_skill("yanyang-dafa",120);
      set_skill("youlong-shenfa",250);
  
   
   set_skill("tianlang-dao",180);
  
   set("gin",1000);
   set("max_gin",1000);
   set("kee",1000);
   set("max_kee",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("force",1500);
   set("max_force",1500);
   create_family("突厥",5,"武士");
    setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
  
}
