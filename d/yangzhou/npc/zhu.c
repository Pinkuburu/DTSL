
inherit F_VENDOR_SALE;
void create()
{
   reload("yz_zhu");
   set_name("朱老板",({ "zhu"}) );
        set("gender", "男性" );
        set("age", 42);
		
   set("long", "这是杂货铺的老板，每天都忙个不停。\n");
   set("shop_id",({ "zhu"}) );  
   set("combat_exp", 200000);
   set("str", 28);
   set("per", 25);
   set_skill("unarmed",80);
   set_skill("dodge",80);
   set_skill("parry",80);
  set("attitude", "peaceful");
  set("vendor_goods",([
     "kedao":__DIR__"obj/kedao",
	"huozhe":__DIR__"obj/huozhe",
	"paper":"/obj/misc/paper",
	"pifeng":"/obj/armor/pifeng",
	"chanzhang":__DIR__"obj/chanzhang",
	"yao": "/d/clone/obj/medicine/jinchuang",
	"dan": "/d/clone/obj/medicine/dan",
	"yangjing-dan": "/d/clone/obj/medicine/yangjing-dan",
	"rose":__DIR__"obj/rose",
  ]));
  
  set("chat_chance",20);
  set("chat_msg",({
   "朱老板笑道：我这里货物很有特色的！\n",
   "朱老板说道：想在黑天看到路吗？快来买“火折子”吧！\n",
   "朱老板笑道：刻刀可以在武器上刻描述，快来买吧！\n",
  }));
  
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
