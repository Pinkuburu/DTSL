inherit NPC;
#include <ansi.h>
#include <job_money.h>
void create()
{
   set_name("边不负",({ "bian bufu","bian","bu","fu" }) );
        set("gender", "男性" );
		
        set("age", 42);
   set("long", "他是阴癸派的高手之一,他的武功仅次于祝玉妍。\n");
       
   set("combat_exp",700000);
   set("str", 25);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("whip",180);
   set_skill("dodge",180);
   set_skill("parry",180);
   set_skill("force",180);
   set_skill("sword",180);
   set_skill("strike",150);
   set_skill("literate",150);
   set_skill("jiutian-huanzhang",180);
   set_skill("cuff",180);
   set_skill("linglong-yuquan",180);
   set_skill("tianmo-dafa",180);
   set_skill("tianmo-jianfa",180);
   set_skill("tianmo-huanzong",180);
   set_skill("tianmo-dai",120);
  
   set("gin",2000);
   set("max_gin",2000);
   set("kee",2000);
   set("max_kee",2000);
   set("sen",2000);
   set("max_sen",2000);
   set("force",2500);
   set("max_force",2500);
   create_family("阴癸派",3,"长老");
   set("class","yin2");
   setup();
   carry_object(__DIR__"obj/changjian")->wield();
  
}


#include "job_npc.c"