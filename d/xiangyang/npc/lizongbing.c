
inherit NPC;

void create()
{
   set_name("李总兵",({ "li"}) );
        set("gender", "男性" );
        set("age", 32);
		
   set("long", "这是车马行的总管李总兵。\n");
       
   set("combat_exp", 200000);
   set("str", 26);
   set("per", 25);
   set_skill("unarmed",150);
   set_skill("sword",150);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("qingxuan-jianfa",150);
   set("sword",({"qingxuan-jianfa"}));
  set("attitude", "peaceful");

   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/gangjian")->wield();
 
}

