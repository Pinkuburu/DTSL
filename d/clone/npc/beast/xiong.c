
inherit NPC;

void create()
{
   set_name("黑熊",({ "hei xiong","xiong"}) );
        set("race", "野兽" );
        set("combat_exp",300000);
     set("long", "这是一只大黑熊，正傻傻地看着你。\n");
	 set("verbs",({"bite","claw","hoof"}));
    set("limbs",({"头","尾巴","腹部","腰部"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/xiongpi");
   ob->move(environment(this_object()));
   message_vision("$N仰头叫了一声，腾地一下倒在了地上。\n",this_object());
   destruct(this_object());
   return;
}

