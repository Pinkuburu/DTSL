
inherit NPC;

void create()
{
   set_name("野兔",({ "ye tu","tu","rabbit"}) );
        set("race", "野兽" );
        set("combat_exp",100000);
     set("long", "这是一只灰白色的野兔。\n");
	 set("verbs",({"claw","hoof"}));
     set("limbs",({"头","尾巴","腹部","腰部"}));
  setup();

}

void die()
{
   object ob;
   ob=new(__DIR__"obj/tutui");
   ob->move(environment(this_object()));
   message_vision("$N晃了几晃，腾地一下倒在了地上。\n",this_object());
   destruct(this_object());
   return;
}

