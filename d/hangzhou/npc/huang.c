
inherit F_VENDOR_SALE;

void create()
{
   reload("hz_huang");
   set_name("黄先生",({ "huang xiansheng","huang"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是药店的老板,他这里的药种类很多的。\n");
    set("shop_id",({ "huang xiansheng","huang"}) );
   set("combat_exp", 60000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "yao": "/d/clone/obj/medicine/jinchuang",
                "dan": "/d/clone/obj/medicine/dan",
                "yangjing-dan": "/d/clone/obj/medicine/yangjing-dan",
	 
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
