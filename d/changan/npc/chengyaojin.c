
inherit NPC;

void create()
{
   set_name("程咬金",({ "cheng yaojin","cheng","yaojin" }) );
        set("gender", "男性" );
        set("age", 39);
   set("long", "这就是长安李阀李世民的手下程咬金。\n他曾经是瓦岗寨的人，后转投程咬金。");
   set("combat_exp", 300000);
   set("str", 29);
   set("per", 20);
   set("attitude", "peaceful");
   set_skill("unarmed",130);
   set_skill("parry",130);
   set_skill("dodge",130);
   set_skill("force",130);
   set_skill("axe",130);
   set_skill("sanban-fu",130);
   set("axe",({"sanban-fu"}));
   set("max_gin",1000);
   set("max_sen",1000);
   set("max_kee",1000);
   set("force",1000);
   set("max_force",1000);
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/axe")->wield();
}

