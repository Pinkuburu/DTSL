
inherit NPC;

#include <ansi.h>
void create()
{
   set_name("李总管",({ "li"}) );
        set("gender", "男性" );
		set("title","货房总管");
       set("age", 42);
   set("long", "他就是宋家堡的货房总管，总管宋家堡的货物。\n");
       
   set("combat_exp", 300000);
   set("str", 28);
   set("per", 24);
   set("attitude", "peaceful");
   set("gin",1000);
   set("eff_gin",1000);
   set("kee",1000);
   set("eff_kee",1000);
   set("sen",1000);
   set("eff_sen",1000);
   set("force",1000);
   set("max_force",1000);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("unarmed",100);
   set_skill("cuff",100);
 
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
 
}

