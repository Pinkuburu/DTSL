//Edit By Subzero
inherit NPC;

void create()
{
   set_name("张捷妤",({ "zhang jieyu","zhang","jieyu" }) );
   set("gender", "女性" );
   set("age", 22);
   set("long", "她一向有着雍容高雅的闲静神态，静静的站在那里，仿佛一
副仕女图，又好似从这个尘世抽离了一般，美的让人不敢相
信她的存在。\n");
   set("shili","li");
   set("combat_exp", 300);
   set("str", 20);
   set("per", 20);
   set("int", 20);
   set("attitude", "peaceful");
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
}
