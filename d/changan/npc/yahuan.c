
inherit NPC;

void create()
{
   set_name("丫鬟",({ "ya huan","ya","huan" }) );
        set("gender", "女性" );
        set("age", 12);
   set("long", "这是一位丫鬟。\n");
       
   set("combat_exp", 2000);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

