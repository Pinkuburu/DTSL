
inherit NPC;

void create()
{
   set_name("松鼠",({ "song shu","shu"}) );
        set("race", "野兽" );
        set("combat_exp",30000);
     set("long", "这是一只调皮的松鼠。\n");
	 set("verbs",({"claw","hoof"}));
     set("limbs",({"头","尾巴","腹部","腰部"}));
  setup();

}


