
inherit NPC;

void create()
{
   set_name("山羊",({ "shan yang","yang","goat"}) );
        set("race", "野兽" );
        set("combat_exp",30000);
     set("long", "这是一只白色的山羊。\n");
	 set("verbs",({"hoof"}));
     set("limbs",({"头","尾巴","腹部","腰部"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/yangjiao");
   ob->move(environment(this_object()));
   message_vision("$N晃了几晃，腾地一下倒在了地上。\n",this_object());
   destruct(this_object());
   return;
}

