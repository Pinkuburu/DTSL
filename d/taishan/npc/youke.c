
inherit NPC;

void create()
{
   set_name("游客",({ "you ke","you","ke" }) );
        set("gender", "男性" );
           set("long", "这是一个普通的游客。\n");
          set("combat_exp", 5000);
   set("str", 10);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

