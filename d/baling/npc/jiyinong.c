
inherit NPC;
#include <job_money.h>
#include <ansi.h>
void create()
{
   set_name("季亦农",({ "ji yinong","ji"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是季亦农,据说他是阴癸派的人。\n");
       
   set("combat_exp",400000);
   set("attitude", "peaceful");
   set_skill("unarmed",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   set_skill("cuff",100);
   set("s_flag",5);
  setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

	
  
