
inherit F_VENDOR_SALE;
void create()
{
   reload("ca_xiaoer4");
   set_name("小二",({ "xiao er","xiao","er" }) );
        set("gender", "男性" );
        set("age", 22);
   set("long", "这是这家杂货铺的小二。\n");
     set("shop_id",({ "xiao er","xiao","er" }) );   
   set("combat_exp", 20000);
   set("str", 22);
   set("per", 22);
   set("attitude", "peaceful");
   set("vendor_goods",([
	   "changjian":__DIR__"obj/changjian",
	   "chouyi":__DIR__"obj/chouyi",
       "shila":"/d/quest/yrs/obj/shila",
           "jiudai":__DIR__"obj/jiudai",
  "caoxie":"/obj/armor/caoxie",
  "pixue":"/obj/armor/pixue",
   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
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
