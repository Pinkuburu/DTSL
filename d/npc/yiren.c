
inherit NPC;

void create()
{
   set_name("艺人",({ "yi ren","yi","ren"}) );
        set("gender", "男性" );
        set("age", 22);
   set("long", "这是一位在合肥卖艺求生的艺人。\n");
       
   set("combat_exp", 50000);
   set("str", 25);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",50);
   set_skill("parry",50);
   set_skill("dodge",50);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void die()
{
	message_vision("$N大声喊道：连卖艺的都杀，我做鬼都不放过你！\n",this_object());
	return ::die();
}

