
inherit NPC;

void create()
{
   set_name("秦叔宝",({ "qin shubao","qin","shubao" }) );
        set("gender", "男性" );
        set("age", 35);
   set("long", "这就是长安李阀李世民的手下秦叔宝。\n他曾经是瓦岗寨的人，后转投李世民。");
   set("combat_exp", 300000);
   set("str", 29);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",130);
   set_skill("parry",130);
   set_skill("dodge",130);
   set_skill("force",130);
   set_skill("qinjia-jianfa",130);
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
   carry_object(__DIR__"obj/jian")->wield();
  
}

