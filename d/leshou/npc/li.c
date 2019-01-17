
inherit F_VENDOR_SALE;
void create()
{
   reload("ls_li");
   set_name("李老板",({ "li laoban","li","laoban"}) );
        set("gender", "男性" );
        set("age", 30);
   set("long", "这是杂货铺的李老板。\n");
    set("shop_id",({ "li laoban","li","laoban"}) );
   set("combat_exp",300000+random(3000));
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "jiudai":__DIR__"obj/jiudai",
	  "blade":__DIR__"obj/blade",
	  "changjian":__DIR__"obj/changjian",
	  "feicui-xianglian":__DIR__"obj/feicui-neck",
	   "huangjin-xianglian":__DIR__"obj/huangjin-neck",
	   "manao-xianglian":__DIR__"obj/manao-neck",
	   "baiyu-jiezhi":__DIR__"obj/baiyu-finger",
	   "hupo-jiezhi":__DIR__"obj/hupo-finger",
	   "kaoya":__DIR__"obj/kaoya",
	  "kaoyangrou":__DIR__"obj/kaoyangrou",
	  "gongbaojiding":__DIR__"obj/gongbao-jiding",
	  "liudoufu":__DIR__"obj/liudoufu",
	  "jiachangliangcai":__DIR__"obj/jiachang-liangcai",
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
