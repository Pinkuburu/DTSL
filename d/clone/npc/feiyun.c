
inherit NPC;

void create()
{
   set_name("斐蕴",({ "fei yun","fei","yu" }) );
        set("gender", "男性" );
        set("age", 42);
        set("tetle","御史大夫");
   set("long", "他是隋朝的御史大夫,杨广手下的红人。\n");
   set("combat_exp",6000);
   set("str", 28);
   set("per", 23);
   setup();
   carry_object(__DIR__"obj/guanfu")->wear();
   carry_object(__DIR__"obj/guanxue")->wear();
}

