
inherit NPC;

void create()
{
   set_name("猴子",({ "hou zi","hou","monkey"}) );
        set("race", "野兽" );
        set("combat_exp",50000);
     set("long", "这是一只顽皮的小猴子。\n");
	 set("verbs",({"claw","hoof"}));
     set("limbs",({"头","尾巴","腹部","腰部"}));
  setup();

}


