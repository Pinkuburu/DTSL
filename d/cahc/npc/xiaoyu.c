//Edit By Subzero
inherit NPC;

void create()
{
   set_name("萧瑀",({ "xiao yu","xiao","yu" }) );
   set("gender", "男性" );
   set("age", 40);
   set("long", "他相貌平平，五短身材，偏是气势逼人，一身官服，不怒而
威，令人不敢直视。此人因其是惰畅帝的妻舅，唐主李渊的
近臣，在大臣中德高望重，地位特殊。\n");
   set("shili","li");
   set("combat_exp", 300000);
   set("str", 20);
   set("per", 16);
   set("int", 27);
   set("attitude", "peaceful");
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
}
