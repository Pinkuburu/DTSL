
inherit NPC;
inherit F_DEALER;
void create()
{
   set_name("赵老板",({ "zhao"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "他就是[醉花楼]的掌柜赵老板。\n");
       
   set("combat_exp", 200000);
   set("str", 27);
   set("per", 24);
   set_skill("force",120);
   set("force",800);
   set("max_force",800);
   set("attitude", "friendly");
   set("vendor_goods",({
	   __DIR__"obj/yu",
	   __DIR__"obj/kaoya",
	   __DIR__"obj/jiudai",
	   __DIR__"obj/zhouzi",
   }));
   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
}

void init()
{
	add_action("do_list","list");
	add_action("do_buy","buy");
}