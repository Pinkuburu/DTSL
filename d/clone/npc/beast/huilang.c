
inherit NPC;

void create()
{
   set_name("灰狼",({ "hui lang","lang","wolf"}) );
        set("race", "野兽" );
        set("combat_exp",200000);
     set("long", "这是一只凶猛的灰狼，正盯着你。\n");
	 set("verbs",({"bite","claw","hoof"}));
     set("attitude","aggressive");
     set("limbs",({"头","尾巴","腹部","腰部"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/langtui");
   ob->move(environment(this_object()));
   message_vision("$N仰头叫了一声，腾地一下倒在了地上。\n",this_object());
   destruct(this_object());
   return;
}

