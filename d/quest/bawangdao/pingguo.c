
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("苹果", ({"apple"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个青苹果。\n");
		set("unit", "个");
		set("value", 20);
		set("food_remaining", 10);
		set("food_supply", 30);
	}
}
