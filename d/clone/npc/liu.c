
inherit NPC;

void create()
{
   set_name("柳青",({ "liu qing","liu"}) );
        set("gender", "女性" );
        set("age", 24);
		
   set("long", "这是宋鲁最宠爱的小妾。\n");
       
   set("combat_exp", 5000);
   set("str", 20);
   set("per", 25);
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
  set("attitude", "peaceful");

   setup();
   carry_object(__DIR__"obj/cloth2")->wear();
 
}

