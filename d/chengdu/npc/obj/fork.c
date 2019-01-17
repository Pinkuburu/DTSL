
#include <weapon.h>
inherit FORK;

void create()
{
	set_name("长枪", ({ "fork"}));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一长枪。\n");
		set("value", 1500);
		
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放了下来。\n");
	}
	init_fork(20,120,120);
	setup();
}
