
inherit NPC;

void create()
{
   set_name("可风道人",({ "ke feng","ke","feng" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "他就是[老君观]的道人可风道人,他也是王世充的手下。\n");
       
   set("combat_exp", 400000);
   set("str", 26);
   set("per", 22);
   set("attitude", "peaceful");
   set("max_kee",1500);
   set("max_sen",800);
   set("max_force",1500);
   set("force",1500);
   set("jiali",80);
   set_skill("dodge",100);
   set_skill("babu-ganchan",100);
   set_skill("whip",100);
   set_skill("fuchen-skill",100);
   set_skill("parry",100);
   setup();
   carry_object(__DIR__"daopao")->wear();
   carry_object(__DIR__"fuchen")->wield();
  
}

