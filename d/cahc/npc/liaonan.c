//Edit By Subzero
inherit NPC;

void create()
{
   set_name("廖南",({ "liao nan","liao","nan" }) );
   set("age", 30);
   set("long", "此人三十多岁，一副油嘴滑舌的小人嘴脸。很少有人知道，他属
于大唐宫禁卫军专责情报的系统，职位是偏将。\n");
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
   set("max_force",1500);
   set("force",1500);
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
}
