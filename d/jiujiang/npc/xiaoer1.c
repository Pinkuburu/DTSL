
inherit F_VENDOR_SALE;
void create()
{
   reload("jj_xiaoer1");
   set_name("店小二",({ "xiao er","xiao","er" }) );
        set("gender", "男性" );
        set("age", 22);
   set("long", "这是这家小饭馆的店小二。\n");
    set("shop_id",({ "xiao er","xiao","er" }) ); 
   set("combat_exp", 200);
   set("attitude", "friendly");
   set("vendor_goods",([
	   "doufu":__DIR__"obj/doufu",
	   "kaoya":__DIR__"obj/kaoya",
	   "huotui":__DIR__"obj/huotui"
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
