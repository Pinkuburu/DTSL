
inherit NPC;

#include <ansi.h>
#include <job_money.h>

void create()
{
   set_name("张须陀",({ "zhang xutuo","zhang"}) );
        set("gender", "男性" );
        set("class","bonze");
        set("age",45);
     	
   set("long", "这是荣阳大海寺的张须陀。\n");
       
   set("combat_exp", 30000);
   set("str", 20);
   set("per", 10);
   
   set_skill("strike",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("cuff",100);
   set_skill("finger",100);
   
   set_skill("jiutian-huanzhang",100);
   set_skill("linglong-yuquan",100);
   set_skill("tianmo-huanzong",100);
   set_skill("dujie-zhi",100);
   
   set("max_kee",2000);
   set("max_gin",2000);
   set("max_sen",2000);
   set("force",2000);
   set("max_force",2000);
   setup();
  
}


#include "job_npc.c"