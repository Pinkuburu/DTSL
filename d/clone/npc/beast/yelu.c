
inherit NPC;

void create()
{
   set_name("梅花鹿",({ "meihua lu","lu"}) );
        set("race", "野兽" );
        set("combat_exp",150000);
     set("long", "这是一只梅花鹿，正在那里吃草。\n");
	 set("verbs",({"claw","hoof"}));
     set("limbs",({"头","尾巴","腹部","腰部"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/lujiao");
   ob->move(environment(this_object()));
   message_vision("$N晃了几晃，腾地一下倒在了地上。\n",this_object());
   destruct(this_object());
   return;
}


