//Edit By Subzero
inherit NPC;

void create()
{
   set_name("程莫",({ "cheng mo","cheng","mo" }) );
   set("gender", "男性" );
   set("age", 40);
   set("long", "此人身为皇宫大内御骑长，专门替皇上操练
马球队的骏马，四十多岁，一副酒色过度的样子。\n");
   set("shili","li");
   set("combat_exp", 300000);
   set("str", 28);
   set("per", 18);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("parry",150);
   set_skill("dodge",150);
   set_skill("force",150);
   set("max_gin",1000);
   set("max_sen",1000);
   set("max_kee",1000);
   set("force",1500);
   set("max_force",1500);
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
}
