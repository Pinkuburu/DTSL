inherit "/std/guard.c";
void create()
{
   set_name("武将",({ "wu jiang","jiang","wu" }) );
   set("gender", "男性" );
   set("age", 32);
   set("long", "这是守卫扬州的武将，看起来十分威风。\n");
  set("combat_exp",800000);
    set("guard","yangzhou");
   set("attitude", "peaceful");
   set_this_skills("high");
   set_all_skill(this_object(),180);

  setup();
}
