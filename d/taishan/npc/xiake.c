
inherit NPC;

void create()
{
   set_name("侠客",({ "xia ke","xia","ke" }) );
        set("gender", "男性" );
           set("long", "这是一个侠客。\n");
          set("combat_exp", 50000);
   set("str", 30);
   set("attitude", "peaceful");
   set_skill("parry",80);
   set_skill("blade",80);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
}

