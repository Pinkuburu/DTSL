
inherit NPC;
inherit JOIN;

void create()
{
   set_name("捕头",({ "bu tou","bu","tou" }) );
        set("gender", "男性" );
        set("age", 40);
   set("long", "这是彭梁的捕头，专门管地方的治安。\n");
   
   set("combat_exp",600000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",180);
   set_skill("dodge",180);
   set_skill("parry",180);
   set_skill("force",180);
   set_skill("sword",180);
   set_skill("cuff",180);
   set_skill("dugu-jianfa",180);
   set("sword",({"dugu-jianfa"}));
   set("max_gin",1500);
   set("max_sen",1500);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/sword")->wield();
}
