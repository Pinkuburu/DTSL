
inherit NPC;
inherit F_DEALER;
void create()
{
   set_name("贞嫂",({ "zhen sao","zhen"}) );
        set("gender", "女性" );
        set("age", 22);
		
   set("long", "她就是老冯的小妾贞嫂。\n");
       
   set("combat_exp", 2000);
   set("str", 20);
   set("per", 25);
   set_skill("unarmed",20);
   set_skill("dodge",20);
   set_skill("parry",20);
  set("attitude", "peaceful");
  set("vendor_goods",({
     __DIR__"obj/baozi",
  }));
   set("chat_chance",20);
   set("chat_msg",({
	   "贞嫂微微一笑:这里的包子都是最好的,快来买啊!\n",
	   "贞嫂温柔道:这里的包子绝对好,我们童叟无欺的.\n",
  }));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}

void init()
{
	add_action("do_list","list");
	add_action("do_buy","buy");
}