
inherit F_VENDOR_SALE;
void create()
{
   reload("gaoli_piaolaoban");
   set_name("朴老板",({ "piao laoban","piao"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是书铺的老板,他的文化水平也是很高的。\n");
   set("shop_id",({ "piao laoban","piao"}) );
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "jing":__DIR__"/d/gaoli/obj/wenxue",	  
  ]));
   setup();
  
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