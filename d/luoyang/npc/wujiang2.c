
inherit "/std/guard.c";

void create()
{
   set_name("武将",({ "wu jiang","jiang","wu" }) );
   set("gender", "男性" );
   set("age", 30);
   set("long", "这是守卫粮仓的武将，看起来十分威风。\n");
       
   set("combat_exp",2000000);
   set("guard","luoyang");
   set("attitude", "peaceful");
   
   set_this_skills("high");
   set_all_skill(this_object(),270);
   
   setup();
    carry_object("/d/yangzhou/npc/obj/cloth")->wear();
  
}
