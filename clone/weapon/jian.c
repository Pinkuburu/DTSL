// 锏

#include <weapon.h>
inherit JIAN;

void create()
{
	set_name("锏", ({"jian"}));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄锏。\n");
		set("value", 1500);
		
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_jian(20,100,100);
	setup();
}
