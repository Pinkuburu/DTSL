
inherit COMBINED_ITEM;

#define HEAL 200
#define HEAL_TYPE "gin"
#define LONG_MSG "这是一包武林人士必备的养精丹，你可以服(fuyong)它来治疗自己的内伤。\n"
#define VALUE 2000


void create()
{
	set_name("养精丹", ({"yangjing dan", "yangjing", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "些");
                           
                set("value", VALUE);
                set("base_unit", "枚");
                set("base_weight", 100);
 		set("long", LONG_MSG);
		set("base_value", VALUE);
		set("heal_up",([
					HEAL_TYPE:HEAL,
					]));
	}
	set_amount(1);
}
