//Edit By Subzero
inherit NPC;

void create()
{
   set_name("颜历",({ "yan li","yan","li" }) );
   set("gender", "男性" );
   set("age", 30);
   set("long", "一个像铁塔般壮健高挺的虬髯粗豪大汉，此人是当年“矛妖”颜平照
之子的颜历。功夫了得。擅长使用一支重铁矛，深得其父真传。因其
父与大唐皇帝李渊交情深厚，顾成年奉父命后一直辅佐李渊左右。\n");
   set("shili","li");
   set("combat_exp", 400000);
   set("str", 28);
   set("per", 18);
   set("attitude", "peaceful");
   set_skill("unarmed",150);
   set_skill("parry",150);
   set_skill("dodge",150);
   set_skill("force",150);
   set_skill("spear",150);
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
   carry_object(__DIR__"obj/potianmao")->wield();
}
