
inherit "/std/guard.c";

void create()
{
   set_name("官兵",({ "bing" }) );
   set("gender", "男性" );
   set("age", 32);
   set("long", "这是一个在巴陵城内巡逻的官兵。\n");
       
   set("combat_exp",800000);
   set("guard","baling");
   set("attitude", "friendly");
   
   set_this_skills("high");
   set_all_skill(this_object(),180);
   
   setup();
 
}
