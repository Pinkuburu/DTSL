
inherit "/std/guard.c";

void create()
{
   set_name("官兵",({ "bing" }) );
   set("gender", "男性" );
   set("age", 32);
   set("long", "这是守卫许城的魏国官兵。\n");
   set("guard","xucheng");
   set("combat_exp",800000);  
   set("attitude", "peaceful");
   
   set_this_skills("high");
   set_all_skill(this_object(),180);
   
   setup();
  
}
