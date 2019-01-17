
inherit F_VENDOR_SALE;
void create()
{
   reload("ly_xiaoer3");
   set_name("店小二",({ "xiao er","xiao","er" }) );
        set("gender", "男性" );
        set("age", 22);
   set("long", "这是这家小饭馆的店小二。\n");
    set("shop_id",({ "xiao er","xiao","er" }) );
   set("combat_exp", 200);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
   set("vendor_goods",([
	   "doufu":__DIR__"obj/doufu",
	   "kaoya":__DIR__"obj/kaoya",
	   "mifan":__DIR__"obj/mifan",
	   "qingfeng-fan":__DIR__"obj/qingfengfan",
	   "jiudai":__DIR__"obj/jiudai",
	   "jitui":__DIR__"obj/jitui",
	   "huotui":__DIR__"obj/huotui",
	   "niurou":__DIR__"obj/niurou",
	   "huasheng":__DIR__"obj/huasheng",
	   "gourou":__DIR__"obj/gourou",
	   "zharoupai":__DIR__"obj/zharoupai",
	   "rougan":__DIR__"obj/rougan",
	   "xiancai":__DIR__"obj/xiancai",
	   "zhengji":__DIR__"obj/zhengji",
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
