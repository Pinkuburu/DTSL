//竹棍

#include <weapon.h>
inherit STICK;

void create()
{
	set_name("竹棍", ({ "zhugun", "zhu","gun" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个竹棍,青竹帮的人都佩带这种武器。\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	init_stick(20,30,30);
	setup();
}
