
inherit F_VENDOR_SALE;
void create()
{
   reload("jj_zahuopuboss");
   set_name("老板",({ "boss" }) );
        set("gender", "男性" );
        set("age", 40);
   set("long", "这是九江杂货铺的老板。\n");
      set("shop_id",({ "boss" }) );
   set("combat_exp",400000);
   set("str",30);
   set("per",2);
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("max_kee",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
   set("vendor_goods",([
	  "shoutao":__DIR__"obj/shoutao",
      "yugou":"/d/job/cisha/yugou",
	  "zhihuan":__DIR__"obj/zhihuan",
	  "botao":__DIR__"obj/botao",
	  "hudun":__DIR__"obj/shield",
	  "zhanpao":__DIR__"obj/zhanpao",
	  "dazao":__DIR__"obj/dazao",
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

