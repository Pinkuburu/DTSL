inherit "/std/guard.c";

void create()
{
   set_name("侍卫",({ "shi wei","wei" }) );
   set("gender", "男性" );
   set("age", 30);
   set("long", "这是守卫皇城的侍卫，神情威严。\n");

   set("combat_exp",800000);
   set("guard","changan");
   set("attitude", "peaceful");

   set_this_skills("high");
   set_all_skill(this_object(),180);

   setup();
    carry_object("/d/yangzhou/npc/obj/cloth")->wear();

}
