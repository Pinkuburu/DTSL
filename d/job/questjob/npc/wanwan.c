

inherit NPC;
#include <ansi.h>
#include <job_money.h>
void create()
{
 
   set_name("婠婠",({ "wan wan","wan"}) );
        set("gender", "女性" );
	set("title","阴癸仙子");	
        set("age", 22);
   set("long", "这是阴癸派的婠婠，她的魔功也是阴癸派数一数二的。\n");
       
   set("combat_exp",3000000);
   set("str", 25);
   set("per", 29);
   set("attitude", "peaceful");
   set_skill("unarmed",280);
   set_skill("dodge",280);
   set_skill("parry",280);
   set_skill("force",280);
   set_skill("sword",280);
   set_skill("strike",280);
   set_skill("cuff",280);
   set_skill("jiutian-huanzhang",280);
   set_skill("linglong-yuquan",280);
   set_skill("tianmo-dafa",280);
   set_skill("tianmo-jianfa",280);
   set_skill("tianmo-huanzong",280);
   set_skill("tianmo-dai",300);
   set_skill("dagger",300);
   set_skill("tianmo-zhan",300);
   
   set("gin",6000);
   set("max_gin",6000);
   set("kee",6000);
   set("max_kee",6000);
   set("sen",6000);
   set("max_sen",6000);
   set("force",6000);
   set("max_force",6000);
   create_family("阴癸派",3,"弟子");
   set("class","yin_guan");
   
   setup();
   
   carry_object(__DIR__"obj/dagger")->wield();
  
}


#include "job_npc.c"