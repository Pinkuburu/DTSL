// 大唐双龙传
 
// xiaoer.c

inherit F_VENDOR_SALE;

void create()
{
       reload("gaoli_lilaoban");
       set_name("李老板", ({"li laoban","li","laoban"}));
       set("shop_id",({"li laoban","li","laoban"}));
       set("shop_title","小吃店老板");
       set("gender", "男性");
        set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
        set("vendor_goods", ([
                "jiudai": "/d/gaoli/obj/jiudai",
                "niangao": "/d/gaoli/obj/niangao",
                "jitui": "/d/gaoli/obj/jitui",
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
