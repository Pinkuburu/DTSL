
inherit NPC;

void create()
{
   set_name("绵羊",({ "mian yang","yang","sheep"}) );
        set("race", "野兽" );
        set("combat_exp",20000);
     set("long", "这是一只绵羊，正在那里吃草。\n");
	 set("verbs",({"hoof"}));
     set("limbs",({"头","尾巴","腹部","腰部"}));
  setup();

}


