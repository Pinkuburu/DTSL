
inherit F_VENDOR_SALE;
void create()
{
    reload("changan_zhubao-boss2");
   set_name("李老板",({ "li laoban","li","lao","ban" }) );
   set("gender", "女性" );
   set("age", 30);
   set("long", "她是珠宝店的老板，看起来风韵犹存。\n");
   set("combat_exp", 500000);   
   set("attitude", "friendly");
   set("vendor_goods",([
	   "feicui-xianglian":__DIR__"obj/feicui-neck2",
	   "huangjin-xianglian":__DIR__"obj/huangjin-neck2",
	   "manao-xianglian":__DIR__"obj/manao-neck2",
	   "baiyu-jiezhi":__DIR__"obj/baiyu-finger2",
	   "hupo-jiezhi":__DIR__"obj/hupo-finger2",
	   
   ]));
   setup();
 //  carry_object(__DIR__"obj/cloth")->wear();
  
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
