
inherit NPC;

void create()
{
   set_name("狐狸",({ "fox","hu","li"}) );
        set("race", "野兽" );
     set("long", "这是一只森林中的狐狸。\n");
	 set_skill("kick",10);
	 set_skill("zhua",10);
	 set("hand",({"zhua"}));
	 set("limbs",({"头","腿","肚子"}));
  setup();

}

