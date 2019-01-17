
inherit COMBINED_ITEM;


#define HEAL 200
#define HEAL_TYPE "kee"
#define LONG_MSG "这是一包武林人士必备的金创药，你可以服(fuyong)它来治疗自己的内伤。\n"
#define VALUE 2000


void create()
{
	set_name("金创药", ({"jinchuang yao", "jinchuang", "yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "些");
                           
                set("value", VALUE);
                set("base_unit", "包");
                set("base_weight", 100);
 		set("long", LONG_MSG);
		set("base_value", VALUE);
		set("heal_up",([
					HEAL_TYPE:HEAL,
					]));
	}
	set_amount(1);
}
