
inherit NPC;

void create()
{
   set_name("狮子",({ "shi zi","zi","shi"}) );
        set("race", "野兽" );
        set("combat_exp",400000);
     set("long", "这是一只凶猛的狮子，正盯着你看。\n");
	 set("verbs",({"bite","claw","hoof"}));
     set("attitude","aggressive");
     set("limbs",({"头","尾巴","腹部","腰部"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/shipi");
   ob->move(environment(this_object()));
   message_vision("$N仰头叫了一声，腾地一下倒在了地上。\n",this_object());
   destruct(this_object());
   return;
}

