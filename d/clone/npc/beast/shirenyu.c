
inherit NPC;

void create()
{
   set_name("食人鱼",({ "yu"}) );
        set("race", "野兽" );
        set("combat_exp",500000);
     set("long", "这是一只凶猛的食人鱼。\n");
	 set("verbs",({"bite"}));
     set("attitude","aggressive");
     set("limbs",({"头","尾巴","腹部","腰部"}));
  setup();

}
