
inherit NPC;

void create()
{
   set_name("蛇",({ "she","snake"}) );
        set("race", "野兽" );
        set("combat_exp",200000);
     set("long", "这是一只蛇，正吐着红信子看着你。\n");
	 set("verbs",({"bite"}));
     set("limbs",({"头","尾巴"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/shedan");
   ob->move(environment(this_object()));
   message_vision("$N抽搐了几下死了。\n",this_object());
   destruct(this_object());
   return;
}

