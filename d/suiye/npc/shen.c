// 大唐双龙传
 
// jia.c

inherit F_VENDOR_SALE;

void create()
{
  reload("suiye_shendaifu");
  set_name("沈大夫", ({"shen daifu", "shen", "daifu"}));
        set("title", "药铺掌柜");
        set("gender", "男性");
  set("shop_id",({"shen dafu", "shen", "dafu"}));
  set("age", 37);
  set("combat_exp", 30000);
   set("long","沈大夫是碎叶最有名的大夫,每天找他看病的人络绎不绝.\n");
  set("age", 38);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);
 set("vendor_goods", ([
                "yao": "/d/clone/obj/medicine/jinchuang",
                "dan": "/d/clone/obj/medicine/dan",
                "yangjing-dan": "/d/clone/obj/medicine/yangjing-dan",
        ]) );
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
