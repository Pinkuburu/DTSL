
inherit NPC;

void create()
{
   set_name("巨蟒",({ "ju mang","mang","she"}) );
        set("race", "野兽" );
     set("long", "这是一条巨蟒，看起来不象是毒蛇。\n");
	 set("verbs",({"bite"}));
     set("limbs",({"头","尾巴","七寸"}));
	 set("attitude","aggressive");
	 setup();

}

