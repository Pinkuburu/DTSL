inherit "/std/guard.c";

void create()
{
   set_name("玄甲兵",({ "xuanjie bing","bing" }) );
   set("gender", "男性" );
   set("age", 30);
   set("long", "这是隶属天策府的玄甲天兵，走来走去的正在巡逻。\n");

   set("combat_exp",800000);
   set("guard","changan");
   set("attitude", "peaceful");

   set_this_skills("high");
   set_all_skill(this_object(),180);

   setup();
    carry_object(__DIR__"obj/xuanjia")->wear();
}
