//Edit By Subzero
inherit NPC;

void create()
{
   set_name("姘妃",({ "pin fei","fei" }) );
   set("gender", "女性" );
   set("age", 25);
   set("long", "她看起来二十多岁，一脸幽怨神色，似乎在思念着家乡或者是某个人吧？\n");
   set("shili","li");
   set("combat_exp", 100000);
   set("per", 28);
   set("attitude", "peaceful");
   set("shili",([
      "name":"lifa_b",
      ]));
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
}
