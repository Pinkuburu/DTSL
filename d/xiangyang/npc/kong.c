
inherit F_VENDOR_SALE;
void create()
{
   reload("xy_kong");
   set_name("孔老板",({ "kong laoban","kong"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是书铺的老板,他的文化水平也是很高的。\n");
   set("shop_id",({ "kong laoban","kong"}) );
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "fojing":__DIR__"obj/fojing",
	   "jing":__DIR__"obj/wenxue",
	   "quanpu":__DIR__"obj/quanpu",
	   "daggerbook":__DIR__"obj/dagger",
  ]));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	::init();
	add_action("do_vendor_list", "list");
}

int regenerate()
{
        set("called", 0);
        return 1;
}