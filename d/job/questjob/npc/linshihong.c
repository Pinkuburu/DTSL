
inherit NPC;

void create()
{
   set_name("林士宏",({ "lin shihong","lin"}) );
        set("gender", "男性" );
        set("age", 32);
		
   set("long", "这是鄱阳会的二龙头。\n");
       
   set("combat_exp", 300000);
   set("str", 20);
   set("per", 15);
   
   set_skill("force",130);
   set_skill("parry",130);
   set_skill("dodge",130);
   
  
   setup();
  
}

